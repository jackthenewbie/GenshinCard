#ifndef LINK_H
#define LINK_H
#include <cpr/cpr.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <vector>
using namespace Json;
class Link{
    private:
        Value value;
        std::string APPLICATION_KEY = "K005mfnwxC6tlYRPqwPnPuCKk24cvVE";
        std::string APPLICATION_KEY_ID = "005a7738f8612960000000002";
        std::string unknown="unknown.png";
        std::string dl_url;
        std::string check(std::string url);
        void raw_link(std::string folder, std::string name, Value* v);
        //image from constellation folder come with a link instead of name
        std::string get_image_from_link(std::string link);
        std::string dl(std::string folder, std::string query, std::string imageKey, std::string image_folder);

    public:
        Link();
        Reader reader;
        std::string demo_dl(){
            return this->dl_url + "/file/genshincard/ganyu.jng";
        }
        //type is circlet, flower, feather, sands, goblet
        std::string artifact(std::string artifact_name, std::string type); //splash gacha image
        std::string character(std::string character_name);
        //talent_type is either auto, skill, burst
        std::string talents(std::string character_name, std::string talent_type);
        //cons is either c1,c2,c3,c4,c5,c6
        std::string cons(std::string character_name, std::string cons);
        std::string stats(std::string stat_name){ //change this to local
            return "Image/Assets/" + stat_name + ".png";
        }
        std::string weapon(std::string weapon_name);
};
#endif