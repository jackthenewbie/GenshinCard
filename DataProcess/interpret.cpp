#include "interpret.h"
#include "GlobalValue.h"
#include "Character.h"
#include "Artifacts.h"
#include "Artifact.h"
#include "Weapon.h"
#include "DrawStat.h"
#include "str.h" //str_util
#include <iostream>
#include <cpr/cpr.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <tuple>
#include <boost/algorithm/string/compare.hpp>
#include <ranges>
#include <vector>
double Interpreter::specialStat(std::string stat, double value){ //for normal stat to match api
    if(stat.at(stat.length()-1) == '_') return value/double(100);
    return value;
}
Value Interpreter::api(std::string folder, std::string query, int level, std::string sign="-", bool dumpResult=true){
    std::string api = "https://genshin-db-api.vercel.app/api/stats?folder=";
    Value vl;
    Reader rd;
    std::string q = api+folder+"&query="+query+"&level="+std::to_string(level)+sign+"&dumpResult="+str_util::toString(dumpResult);
    cpr::Response r = cpr::Get(cpr::Url{q});
    rd.parse(r.text, vl);
    return vl;
}
Interpreter::Interpreter(const char *good_json)
{
    std::cout << "Interpreting..." << std::endl;
    ifstream ifs(good_json);
    this->reader.parse(ifs, this->good_json);
}
Interpreter::Interpreter(std::string data)
{
    std::cout << "Interpreting..." << std::endl;
    this->reader.parse(data, this->good_json);
}
Interpreter::~Interpreter()
{
    std::cout << "Destroyed" << std::endl;
}
Value Interpreter::Good_json(){return this->good_json;}
void Interpreter::Target_json(){ //data from api & good_json -- api is 1, good_json(partial) is 0
    for(auto it = this->characters.begin(); it != this->characters.end(); it++){
        std::cout<<(it->first).at(1)<<std::endl;
    }
}
//void Interpreter::Target_json(){std::cout<< this->target_json;}
Value Interpreter::getPlainStat(std::string name, int level, int ascension, bool dumpResult=false){
    std::string sign = "-";
    if(level/10 -2 == ascension) sign="+";
    cpr::Response r = cpr::Get(cpr::Url{"https://genshin-db-api.vercel.app/api/stats?folder=characters&query="+name+"&level="+std::to_string(level)+sign+"&dumpResult="+str_util::toString(dumpResult)});
    this->reader.parse(r.text, this->target_json);
    return this->target_json;
}
void Interpreter::baseStats(){
    for(auto character = this->characters.begin(); character != this->characters.end(); character++){
        std::cout << "Calculating base stats..." << std::endl;
        auto api = (character->first).at(1);
        std::string specialized = get_bonus(api["result"]["substat"].asString());
        (character->second).set_specialized(specialized);
        double specialized_stat = api["stats"]["specialized"].asDouble();
        auto keys = api["stats"].getMemberNames();
        (character->second).set_stat(specialized , specialized_stat);
        for(auto key : keys){
            if(str_util::is_string_equal(key, "ascension") || 
               str_util::is_string_equal(key, "level") || 
               str_util::is_string_equal(key, "specialized"))
               continue;
            cout<<get_bonus(key)<<" "<<api["stats"][key].asDouble()<<endl;
            (character->second).set_stat(get_bonus(key), api["stats"][key].asDouble());
        }
        std::vector<std::string> statdf {"critDMG_", "critRate_", "enerRech_"};
        std::vector<double> valdf {0.5, 0.05, 1};
        std::vector<std::string>::iterator istatdf = statdf.begin();
        std::vector<double>::iterator ivaldf  = valdf.begin();
        while(istatdf != statdf.end() && ivaldf != valdf.end()){
            if((character->second).get_stat(*istatdf)*100 == 0) 
                (character->second).set_stat(*istatdf, *ivaldf);
            istatdf++;
            ivaldf++;
        }
        
        //if((character->second).get_stat("critDMG_")*100 == 0) (character->second).set_stat("critDMG_", 0.5);
        //if((character->second).get_stat("critRate_")*100 == 0) (character->second).set_stat("critRate_", 0.05);
        //if((character->second).get_stat("enerRech_")*100 == 0) (character->second).set_stat("enerRech_", 1);

        
    }
}
std::string Interpreter::as2sign(int ascension, int level){
    std::string sign = "-";
    if(level/10 -2 == ascension) sign="+";
    return sign;
}
void Interpreter::igniteChars(std::set<std::string> names){
    std::cout << "Finding character..." << std::endl;
    std::set<std::string>::iterator it;
    for(it = names.begin(); it != names.end(); it++){
        //this->getPlainStat(*it, 1, 0, true);
        this->target_json = this->api("characters", *it, 1);
        for(Json::Value i : this->good_json["characters"]){
            if(str_util::is_string_equal(i["key"].asString(), this->target_json["filename"].asString())){
                std::cout << "Scraping from data..." << std::endl;
                //this->getPlainStat(*it, i["level"].asInt(), i["ascension"].asInt(), true);
                //calculate sign
                std::string sign = as2sign(i["ascension"].asInt(), i["level"].asInt());
                this->target_json = this->api("characters", *it, i["level"].asInt(), sign);
                std::cout << "Found level of "+*it+" is: " << i["level"] << std::endl;
                //std::cout<< this->target_json << std::endl; //see ganyuApi.json example
                //std::string fileName=target_json.get("filename", i["key"].asString()).asString(); //different ways of get value: safe way
                std::string fileName = i["key"].asString(); //use name from GOOD_json
                int level = target_json["stats"]["level"].asInt(); //not so safe way
                int rarity = std::stoi(target_json["result"]["rarity"].asString()); // original is string (dont know why), convert to int
                int ascension = target_json["stats"]["ascension"].asInt();
                int constellation = i["constellation"].asInt();
                std::tuple <int, int, int> talents = std::make_tuple(i["talent"]["auto"].asInt(), i["talent"]["skill"].asInt(), i["talent"]["burst"].asInt());
                Character *c = new Character(fileName, level, rarity, ascension, constellation, talents);
                std::vector<Value> temp;
                temp.push_back(i);
                temp.push_back(target_json);
                this->characters.insert(std::pair<std::vector<Value>,Character>(temp,*c));

            }
        }
    }
}
void Interpreter::printChars(){
    for(auto it = this->characters.begin(); it != this->characters.end(); it++){
        (it->second).printCharacter();
    }
}
void Interpreter::printArtifacts(){
    for(auto it = this->characters.begin(); it != this->characters.end(); it++){
        (it->second).printArtifacts();
    }
}
void Interpreter::print(){
    for(auto it = this->characters.begin(); it != this->characters.end(); it++){
        (it->second).printCharacter();
        (it->second).printArtifacts();
        (it->second).printWeapon();
    }
}
void Interpreter::igniteArtifacts(){
    //std::cout << "Finding artifacts..." << std::endl;
    for(auto character_ = this->characters.begin(); character_ != this->characters.end(); character_++){
        for(Json::Value i : this->good_json["artifacts"]){
            if(str_util::is_string_equal(i["location"].asString(), (character_->first).at(0)["key"].asString() )){
                std::cout << "Found level of \""+i["setKey"].asString()
                            +"\" type:" + i["slotKey"].asString()
                            +" is: " << i["level"] 
                            <<" of character: "
                            +i["location"].asString()<< std::endl;
                //std::cout << "Looking for basic stat..." << std::endl;
                std::string name=i["setKey"].asString(); //different ways of get value: safe way
                int level = i["level"].asInt(); //not so safe way
                int rarity = i["rarity"].asInt();
                std::string type = i["slotKey"].asString();
                Artifact *a = new Artifact(name, type, rarity, level); //Basic info of an artifact
                //std::cout << "Looking for main stat..." << std::endl;
                double mainStat = artifact5_main_stats.at(i["mainStatKey"].asString()).at(level);
                std::string mainKey = i["mainStatKey"].asString();
                a->set_main_stat(mainKey, 
                                 this->specialStat(mainKey, mainStat)); // stop here --------------------------------------
                //set substat
                std::map<std::string, double> sub_stats;
                for(Json::Value sub : i["substats"]){
                    double subStat=sub["value"].asDouble();
                    std::string subKey=sub["key"].asString();
                    sub_stats.insert(std::pair<std::string, double>(subKey, this->specialStat(subKey,subStat)));
                }
                //insert substat
                a->set_sub_stat(sub_stats);
                character_->second.set_artifact(*a);
            }
        }
        for(Json::Value i : this->good_json["weapons"]){
            if(str_util::is_string_equal(i["location"].asString(), (character_->first).at(0)["key"].asString() )){
                std::cout << "Found level of \""+i["key"].asString()
                            +" is: " << i["level"] 
                            <<" of character: "
                            +i["location"].asString()<< std::endl;
                //std::cout << "Looking for basic stat..." << std::endl;
                std::string name=i["key"].asString(); //different ways of get value: safe way
                int level = i["level"].asInt(); //not so safe way
                int ascension = i["ascension"].asInt();
                int refinement = i["refinement"].asInt();
                //fetch stat for weapon from api
                std::string sign =as2sign(i["ascension"].asInt(), i["level"].asInt());
                Value vl = this->api("weapons", name, level, sign);
                std::string bonus;
                try{
                    bonus = vl["result"]["substat"].asString();
                }
                catch(...){
                    cout<<"Error trying to get substat for \n" << name <<endl;
                    return;
                }
                Weapon *w = new Weapon(name, level, std::stoi(vl["result"]["rarity"].asString()), ascension, refinement); //Basic info of an artifact
                //std::cout << "Looking for main stat..." << std::endl;
                w->set_main_stat("atk", vl["stats"]["attack"].asDouble()); // stop here --------------------------------------
                //set substat
                w->set_sub_stat(get_bonus(bonus), std::stod(vl["stats"]["specialized"].asString()));
                character_->second.set_weapon(*w);
            }
        }
            
    }
}
void Interpreter::drawBasic(){
    for(auto it = this->characters.begin(); it != this->characters.end(); it++){
        DrawStat d(&(it->second));
        d.drawBasic(820,212,58);
        d.drawBonus(549, 820, 562+58, 58, "character", std::vector<std::string>{"cryo_dmg_"});
        d.drawWeapon(470, 20, 620, 620+200, 45, 30, 100);
        InitializeMagick("/home/ser3_decoyer/repo/GenshinCard/Image/TOP.png");
        Image image;
        image.read("/home/ser3_decoyer/repo/GenshinCard/Image/TOP.png");
        image.draw(d.get_drawList());
        image.write("/home/ser3_decoyer/repo/GenshinCard/Image/Ganyu.png");
    }
}