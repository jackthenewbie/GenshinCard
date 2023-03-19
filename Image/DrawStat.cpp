#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <Magick++.h>
#include "DrawStat.h"
#include "expre_algo.h"
#include "GlobalValue.h"
#include "str.h"
#include "Character.h"
#include "Artifacts.h"
using namespace Magick;
DrawStat::DrawStat(Character* character){
    this->character = character;
}
std::vector<Drawable> DrawStat::get_drawList(){
    return this->drawList;
}
void DrawStat::calculateAll(){
    for (auto& stat : this->stats){ //artifact total stats
       // double temp = character->get_stat(stat.first);
       double temp = 0;
        for(Artifact& artifact : (character->get_artifacts()).get_artifacts()){
            std::set<std::string> subs = artifact.get_sub_stats();
            auto it = subs.find(stat.first);
            if (it != subs.end()){
                //std::cout<<"Found stat"<<stat<<":"<<artifact.get_sub_stat(stat)<<" in "<<artifact.get_set()<<" type "<<artifact.get_type()<<std::endl;
                temp += artifact.get_sub_stat(stat.first);
            }
            if(artifact.get_main_stat() == stat.first){
                //std::cout<<"Found stat"<<stat<<":"<<artifact.get_main_stat(stat)<<" in "<<artifact.get_set()<<" type "<<artifact.get_type()<<std::endl;
                temp += artifact.get_main_stat(true);
            }
        }
        std::cout<<"Stat "<<stat.first<<" is "<<temp<<std::endl;
        this->stats[stat.first] = temp;
    }
    this->character->set_stat("atk", (character->get_weapon()).get_main_stat(true) + this->character->get_stat("atk"));
    this->stats.at((character->get_weapon()).get_sub_stat()) += (character->get_weapon()).get_sub_stat(true);
    //set bonus2pc to stats
    auto bonus = character->get_artifacts().get_bonus2pc();
    for(auto& stat : bonus){
        this->stats.at(stat.first) += stat.second;
    }
    for(auto& stat : this->stats) std::cout<<"Character has "<<stat.first<<" is "<<character->get_stat(stat.first)<<std::endl;

    for(auto& stat : this->stats){
        if(!stat.first.ends_with("_")){
            double totalstat =this->stats.at(stat.first);
            double totalstat_ = this->stats.at(stat.first + "_");   
            try{
                this->stats.at(stat.first) = 
                this->character->get_stat(stat.first)*((this->character->get_stat(stat.first + "_") + totalstat_)) + totalstat;
            }catch(Exception& e){
                std::cout<<"Can't with "<<stat.first<<" error: "<< e.what()<<std::endl;
            }
        }
        this->stats.at(stat.first) += (this->character->get_stat(stat.first));
        std::cout<<stat.first<<" has value: "<<this->stats.at(stat.first)<<std::endl;
    }
    this->calculate = true;
}
void DrawStat::drawBasic(int x, int y, int space){
    if(!calculate){calculateAll();}
    std::vector<std::string> displayStat{
        "hp",
        "atk",
        "def",
        "eleMas",
        "critRate_",
        "critDMG_",
        "enerRech_"
    };
    this->drawList.push_back(DrawableFont(FONT));
    this->drawList.push_back(DrawablePointSize(FONT_SIZE));
    this->drawList.push_back(DrawableFillColor("white"));
    for(auto& stat : displayStat){
        std::string val;
        if(stat.ends_with("_")){
            val = str_util::rm0tail(std::to_string(round(this->stats.at(stat)*100 *10)/10)) + "%";
        }else val = std::to_string(round(this->stats.at(stat)));
        this->drawList.push_back(DrawableText(x, y, str_util::rm0tail(val)));
        y+=space;
    }
}
void DrawStat::drawBonus(int xstat, int xval, int y, int spacey, std::string mode, std::vector<std::string> displayStat, bool skipBasic){
    std::set<std::string> skipPrint{
        "hp",
        "atk",
        "def",
        "eleMas",
        "critRate_",
        "critDMG_",
        "enerRech_"
    };
    if(!calculate){calculateAll();}
    displayStat.erase(std::remove_if(
        displayStat.begin(), displayStat.end(), [&](std::string s)
        {return !stats.contains(s);}), displayStat.end()
    );
    //insert specialized stat
    if(mode == "character"){
        displayStat.push_back(this->character->get_specialized());
        std::cout<<"Drawing stat :"<<this->character->get_specialized()<<std::endl;
    }
    
    expr_algo::remove_duplicate(displayStat);
    this->drawList.push_back(DrawableFont(FONT));
    this->drawList.push_back(DrawablePointSize(FONT_SIZE));
    this->drawList.push_back(DrawableFillColor("white"));
    for(auto& stat : displayStat){
        if( (skipBasic && skipPrint.contains(stat)) ||
            this->stats.at(stat)*100 == 0) //skip 0% stat
            {continue;}
        std::string val;
        if(stat.ends_with("_")){
            val = str_util::rm0tail(std::to_string(round(this->stats.at(stat)*100 *10)/ 10)) + "%";
        }else val = std::to_string(round(this->stats.at(stat)));
        /*
        Image icon(stat_link(stat));
        drawList.push_back(xstat - icon.size().width() - int(round(FONT_SIZE/3), y - FONT_SIZE + int(round(FONT_SIZE/4)), 0, 0, icon, OverCompositeOp);
        */
        this->drawList.push_back(DrawableText(xstat, y, display(stat)));
        this->drawList.push_back(DrawableText(xval, y, str_util::rm0tail(val)));
        y+=spacey;
    }
}
//void DrawStat::iconToDrawlist(std::string icon, int x, int y){
//    Image img(icon);
//    img.resize(Geometry(FONT_SIZE, FONT_SIZE));
//    this->drawList.push_back(x - img.size().width() - int(round(FONT_SIZE/3)), //x cordinate
//                        y - FONT_SIZE + int(round(FONT_SIZE/4)), //y cordinate
//                        img, OverCompositeOp));
//}
void DrawStat::drawWeapon(int ximg, int yimg, int xstat, int xval, int y, int spacey, int icon_size){
    if(!calculate){calculateAll();}
    Image wp("/home/ser3_decoyer/repo/GenshinCard/Image/UI_EquipIcon_Bow_Amos_Awaken#63040.png");
    wp.resize(Geometry(icon_size, icon_size));
    this->drawList.push_back(DrawableFont(FONT));
    this->drawList.push_back(DrawableCompositeImage(ximg, yimg, 0, 0, wp, OverCompositeOp));
    //draw weapon name
    this->drawList.push_back(DrawablePointSize(FONT_SIZE + 3));
    this->drawList.push_back(DrawableText(xstat, y, this->character->get_weapon().get_name()));
    y+=spacey;
    this->drawList.push_back(DrawablePointSize(FONT_SIZE));
    //draw weapon main stat
    this->drawList.push_back(DrawableText(xstat, y, display(this->character->get_weapon().get_main_stat())));
    //draw weapon main stat value
    this->drawList.push_back(DrawableText(xval, y, str_util::rm0tail(std::to_string(round(this->character->get_weapon().get_main_stat(true))))));
    //main stat icon
    //iconToDrawlist(stat_link(this->character->get_weapon().get_main_stat()), xstat, y);
    /*
    Image icon(stat_link(this->character->get_weapon().get_main_stat()));
    icon.resize(Geometry(FONT_SIZE, FONT_SIZE));
    drawList.push_back(xstat - icon.size().width() - int(round(FONT_SIZE/3), //x cordinate
                        y - FONT_SIZE + int(round(FONT_SIZE/4)), //y cordinate
                        0, 0, icon, OverCompositeOp);
    */
    y+=spacey;
    //draw weapon sub stat
    this->drawList.push_back(DrawableText(xstat, y, display(this->character->get_weapon().get_sub_stat())));
    //draw weapon sub stat value
    double d_val = this->character->get_weapon().get_sub_stat(true) *100;
    std::string s_val = "";
    if(this->character->get_weapon().get_sub_stat().ends_with("_"))
        s_val = str_util::rm0tail(std::to_string(round(d_val*10)/10)) + "%";
    else s_val = str_util::rm0tail(std::to_string(round(d_val))) + "%";
    this->drawList.push_back(DrawableText(xval, y, s_val));
    //sub stat icon
    //iconToDrawlist(stat_link(this->character->get_weapon().get_sub_stat()), xstat, y);
    /*
    Image icon(stat_link(this->character->get_weapon().get_sub_stat()));
    icon.resize(Geometry(FONT_SIZE, FONT_SIZE));
    drawList.push_back(xstat - icon.size().width() - int(round(FONT_SIZE/3), //x cordinate
                        y - FONT_SIZE + int(round(FONT_SIZE/4)), //y cordinate
                        0, 0, icon, OverCompositeOp);
    */
    y+=spacey;
    //draw weapon level and refinement
    std::string cons = "R"+std::to_string(this->character->get_weapon().get_refinement());
    std::string lv = "Lv. " +std::to_string(this->character->get_weapon().get_level()) + "/90";
    this->drawList.push_back(DrawableText(xstat, y, cons + "  " + lv));
}
