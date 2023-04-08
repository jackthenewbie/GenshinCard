#include "link.h"
#include <cpr/cpr.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <vector>
using namespace Json;
Link::Link(){
    cpr::Response r = cpr::Get(cpr::Url{"https://api.backblazeb2.com/b2api/v2/b2_authorize_account"},
              cpr::Authentication{ APPLICATION_KEY_ID, APPLICATION_KEY, cpr::AuthMode::BASIC });
    reader.parse(r.text, value);
    this->dl_url = value["downloadUrl"].asString();
}
std::string Link::check(std::string url){
    cpr::Response r = cpr::Get(cpr::Url{url});
    if(r.status_code == 200) return url;
    else return this->unknown;
}
void Link::raw_link(std::string folder, std::string name, Value* v){
    Reader reader;
    Value value;
    std::string url;
    if(folder=="characters") url = "https://genshin-db-api.vercel.app/api/characters?&query="+name;
    else if(folder == "artifacts") url = "https://genshin-db-api.vercel.app/api/artifacts?query="+name;
    else if(folder == "talents") url = "https://genshin-db-api.vercel.app/api/talents?query=" + name;
    else if(folder == "cons") url = "https://genshin-db-api.vercel.app/api/constellations?query=" + name;
    else if(folder == "weapons") url = "https://genshin-db-api.vercel.app/api/weapons?query=" + name;
    cpr::Response r = cpr::Get(cpr::Url{url});
    if(r.status_code == 200 && r.text.length() > 20){
        reader.parse(r.text, *v);
    }
    else{
        std::cout<<"Error: "<<r.status_code<<"(if 200 possibly couldn't found)"<<std::endl;
        v=nullptr;
    }
}
std::string Link::get_image_from_link(std::string link){
    std::string image_name="";
    for(int i = link.length()-1; i >= 0; i--){
        if(link[i] == '/') break;
        else image_name += link[i];
    }
    return image_name;
}
std::string Link::dl(std::string folder, std::string query, std::string imageKey, std::string image_folder){
    Value value;
    Value *v = &value;
    this->raw_link(folder, query, v);
    std::string file_name, dl_url;
    if(v != nullptr){
        if(folder == "characters")
            file_name = (*v)["images"][imageKey].asString();
        else if(folder == "talents" || folder == "artifacts" || folder == "weapons")
            file_name = (*v)["images"][imageKey].asString();
        else if(folder == "cons"){
            file_name = this->get_image_from_link((*v)["images"][imageKey].asString());
        }
            
        //swap folder name to dest folder name
        //change dl_url to local to use local assets (keep file_name) + return dl_url instead of return this->check(dl_url); m
        dl_url = this->dl_url + "/file/genshincard" + image_folder + "/" + file_name + ".png";
    }
    
    else{
        dl_url = this->dl_url + "/file/genshincard" + "/unknown.png";
    }
    return this->check(dl_url);
}
std::string Link::artifact(std::string artifact_name, std::string type){
    //attempt to make our own assets
    //std::string dl_url = this->dl_url + "/file/genshincard/artifacts/" + artifact_name + ".png";
    return this->dl("artifacts", artifact_name, "name"+type, "/upload/artifacts");//to change image folder
}
std::string Link::character(std::string character_name){
    return this->dl("characters", character_name, "namegachasplash", "/upload/characters"); //to change image folder    
}
std::string Link::talents(std::string character_name, std::string talent_type){
    std::string talent_query;
    if(talent_type == "auto") talent_query = "combat1";
    else if(talent_type == "skill") talent_query = "combat2";
    else if(talent_type == "burst") talent_query = "combat3";
    return this->dl("talents", character_name, talent_query, "/upload/talents");
}
std::string Link::cons(std::string character_name, std::string cons){
    return this->dl("characters", character_name, cons, "/upload/cons");
}
std::string Link::weapon(std::string weapon_name){
    return this->dl("weapons", weapon_name, "nameawakenicon", "/upload/weapons");
}