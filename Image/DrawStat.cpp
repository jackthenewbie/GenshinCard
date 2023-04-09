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
#include "Link.h"
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
            std::set<std::string> *subs = artifact.get_sub_stats();
            auto it = subs->find(stat.first);
            if (it != subs->end()){
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
            }catch(std::exception& e){
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
void DrawStat::drawBonus(int xstat, int xval, int y, int spacey, int xicon, int yicon, int icon_size, std::string mode, std::vector<std::string> displayStat, bool skipBasic){
    Link l;
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
        
        Image icon(l.stats(stat));
        icon.resize(Geometry(icon_size, icon_size));
        drawList.push_back(DrawableCompositeImage(xicon, yicon, 0, 0, icon, OverCompositeOp));
        
        this->drawList.push_back(DrawableText(xstat, y, display_stat(stat)));
        this->drawList.push_back(DrawableText(xval, y, str_util::rm0tail(val)));
        y+=spacey;
        yicon+=spacey;
    }
}
void DrawStat::iconToDrawlist(std::string icon, int x, int y){
    Image img(icon);
    img.resize(Geometry(FONT_SIZE, FONT_SIZE));
    this->drawList.push_back(DrawableCompositeImage(x - img.size().width() - int(round(FONT_SIZE/3)), //x cordinate
                             y - FONT_SIZE + int(round(FONT_SIZE/4)), //y cordinate
                             0, 0, img, OverCompositeOp));
}
void DrawStat::drawWeapon(int ximg, 
                          int yimg,
                          int xname,
                          int yname,
                          int name_size, 
                          int xstat, 
                          int ystat,
                          int mainstat_size,
                          int xval, 
                          int yval,
                          int spacex, 
                          int spacey, 
                          int icon_size){
    Link l;
    std::vector<std::pair<int, int>> substat_pos;
        for(int row=0; row<2; row++){
            for(int col=0; col<2; col++){
                substat_pos.push_back(std::pair<int, int>(col, row));
            }
        }
    std::vector<std::string> display;
    //draw mainstat value
    display.push_back(str_util::rm0tail(std::to_string(round(this->character->get_weapon().get_main_stat(true)))));
    //draw cons
    std::string cons = "R"+std::to_string(this->character->get_weapon().get_refinement());
    display.push_back(cons);
    //draw substat value
    double d_val = this->character->get_weapon().get_sub_stat(true);
    std::string s_val = "";
    if(this->character->get_weapon().get_sub_stat().ends_with("_"))
        s_val = str_util::rm0tail(std::to_string(round(d_val*1000)/10)) + "%";
    else s_val = str_util::rm0tail(std::to_string(round(d_val)));
    display.push_back(s_val);
    //draw weapon level and refinement
    std::string lv = "Lv. " +std::to_string(this->character->get_weapon().get_level()) + "/90";
    display.push_back(lv);

    if(!calculate){calculateAll();}
    Image wp(l.weapon(this->character->get_weapon().get_name()));
    wp.resize(Geometry(icon_size, icon_size));
    this->drawList.push_back(DrawableFont(FONT));
    this->drawList.push_back(DrawableCompositeImage(ximg, yimg, 0, 0, wp, OverCompositeOp));
    //draw weapon namethis->character->get_weapon().get_mainstat()
    this->drawList.push_back(DrawablePointSize(name_size));
    this->drawList.push_back(DrawableText(xname, yname, this->character->get_weapon().get_name()));
    
    //draw mainstat icon
    Image mstat(l.stats(this->character->get_weapon().get_main_stat()));
    mstat.resize(Geometry(mainstat_size, mainstat_size));
    this->drawList.push_back(DrawableCompositeImage(xstat, ystat, 0, 0, mstat, OverCompositeOp));
    //draw substat icon
    Image sstat(l.stats(this->character->get_weapon().get_sub_stat()));
    sstat.resize(Geometry(mainstat_size, mainstat_size));
    this->drawList.push_back(DrawableCompositeImage(xstat, ystat+spacey, 0, 0, sstat, OverCompositeOp));
    
    this->drawList.push_back(DrawablePointSize(FONT_SIZE));
    for(int i=0; i<display.size(); i++){
        this->drawList.push_back(DrawableText(xval + substat_pos.at(i).first*spacex, 
                                              yval + substat_pos.at(i).second*spacey, 
                                              display.at(i)));
    }
}
void DrawStat::drawArtifact(int ximg, 
                           int yimg,
                           int FONT_SIZE_name,
                           int xname,
                           int yname,
                           int FONT_SIZE_mainstat, 
                           int xmainstat,
                           int ymainstat,
                           int xmainval,
                           int ymainval,
                           int mainstat_size,
                           int FONT_SIZE_substat, 
                           int xsubstat,
                           int ysubstat,
                           int xsubval,
                           int ysubval,
                           int substat_size, 
                           int spacesubx,
                           int spacesuby, 
                           int icon_size)
{
    Link icons;
    Artifacts artifacts = this->character->get_artifacts();
    stat_link("atk");
    if(!calculate){calculateAll();}
    display_stat("atk");
    for(Artifact a : artifacts.get_artifacts()){
        std::string image_url = icons.artifact(a.get_set(), a.get_type());
        Image artifact(image_url);
        artifact.resize(Geometry(icon_size, icon_size));
        artifact.alpha(true);
        artifact.evaluate (AlphaChannel, MultiplyEvaluateOperator, 0.7);
        this->drawList.push_back(DrawableCompositeImage(ximg, yimg, 0, 0, artifact, OverCompositeOp));
        yimg+=140;
        //draw artifact name
        this->drawList.push_back(DrawableFont(FONT));
        this->drawList.push_back(DrawablePointSize(FONT_SIZE_name));
        this->drawList.push_back(DrawableText(xname, yname, a.get_set()));
        yname+=140;
        Image iconmain(icons.stats(a.get_main_stat()));
        iconmain.resize(Geometry(mainstat_size, mainstat_size));
        this->drawList.push_back(DrawableCompositeImage(xmainstat, ymainstat, 0, 0, iconmain, OverCompositeOp));
        ymainstat+=140;
        this->drawList.push_back(DrawablePointSize(FONT_SIZE_mainstat));
        double mainval = a.get_main_stat(true);
        std::string val;
        if(a.get_main_stat().ends_with("_"))
        val = str_util::rm0tail(std::to_string(round(mainval*1000)/10)) + "%";
        else val = str_util::rm0tail(std::to_string(round(mainval)));
        
        //this->drawList.push_back(DrawableGravity(CenterGravity));
        this->drawList.push_back(DrawableText(xmainval, ymainval, val));
        ymainval+=140;
        std::vector<std::pair<int, int>> substat_pos;
        for(int row=0; row<2; row++){
            for(int col=0; col<2; col++){
                substat_pos.push_back(std::pair<int, int>(col, row));
            }
        }
        //------------------SUBSTATS------------------
        std::set<std::string> *substats = a.get_sub_stats();
        auto atribute = substats->begin(); 
        auto pos = substat_pos.begin();
        while(atribute != substats->end() && pos != substat_pos.end())
        {
            std::string temp;
            temp = *atribute;
            std::cout<<"Current substat: "<<temp<<std::endl;
            int at_x = pos->first;
            int at_y = pos->second;
            Image icon(icons.stats(temp));
            icon.resize(Geometry(substat_size, substat_size));
            this->drawList.push_back(DrawableCompositeImage(xsubstat+at_x*spacesubx, ysubstat+at_y*spacesuby, 0, 0, icon, OverCompositeOp));
            this->drawList.push_back(DrawablePointSize(FONT_SIZE_substat));
            double subval = a.get_sub_stat(temp);
            if(temp.ends_with("_"))
            val = str_util::rm0tail(std::to_string(round(subval*1000)/10)) + "%";
            else val = str_util::rm0tail(std::to_string(round(subval)));
        
            this->drawList.push_back(DrawableText(xsubval+at_x*spacesubx, ysubval+at_y*spacesuby, val));

            atribute++, pos++;
        }
        ysubstat+=140;
        ysubval+=140;
    }
}
void DrawStat::drawTalents(int ximg,
                           int yimg,
                           int spacex,
                           int spacey,
                           int icon_size,
                           int xframe,
                           int yframe,
                           int frame_size)
{
    
}
Image* DrawStat::drawBackground(std::string ground_back, int xsplash, int ysplash, std::string ground_front, int shiftFront){
    Link image;
    InitializeMagick(NULL);
    Image *ImageGround_back = new Image(ground_back);
    ImageGround_back->resize(Geometry(1280, 720));
    Image gacha_splash(image.character(this->character->get_name()));
    ImageGround_back->draw(DrawableCompositeImage(xsplash, ysplash, 0, 0, gacha_splash, OverCompositeOp));
    Image ImageGround_front(ground_front);
    ImageGround_front.matteColor(Color("white"));
    ImageGround_back->draw(DrawableCompositeImage(shiftFront        , 0, 0, 0,ImageGround_front, OverCompositeOp));
    return ImageGround_back;
    
}
DrawableList* DrawStat::drawBack(int xsplash, int ysplash, std::string ground_front, int shiftFront){
    Link image;
    DrawableList* drawList = new DrawableList();
    Image gacha_splash(image.character(this->character->get_name()));
    drawList->push_back(DrawableCompositeImage(xsplash, ysplash, 0, 0, gacha_splash, OverCompositeOp));
    Image ImageGround_front(ground_front);
    ImageGround_front.matteColor(Color("white"));
    drawList->push_back(DrawableCompositeImage(shiftFront, 0, 0, 0, ImageGround_front, OverCompositeOp));
    return drawList;
}
