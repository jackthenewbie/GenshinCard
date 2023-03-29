#include <cpr/cpr.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <vector>
using namespace Json;
class link{
    private:
        Value value;
        std::string APPLICATION_KEY = "K005mfnwxC6tlYRPqwPnPuCKk24cvVE";
        std::string APPLICATION_KEY_ID = "005a7738f8612960000000002";
        std::string unknown="unknown.png";
        std::string dl_url;
        std::string check(std::string url){
            cpr::Response r = cpr::Get(cpr::Url{url});
            if(r.status_code == 200) return url;
            else return this->unknown;
        }
        Value *raw_link(std::string folder, std::string name){
            Reader reader;
            Value value;
            std::string url = "https://genshin-db-api.vercel.app/api/stats?folder="+folder+"&query="+name+"&dumpResult=true";
            if(folder == "artifacts") url = "https://genshin-db-api.vercel.app/api/artifacts?query="+name+"&matchAltNames=false&verboseCategories=true";
            cpr::Response r = cpr::Get(cpr::Url{url});
            if(r.status_code == 200 && r.text.length() > 20){
                reader.parse(r.text, value);
                return &value;
            }
            else{
                std::cout<<"Error: "<<r.status_code<<"(if 200 possibly couldn't found)"<<std::endl;
                return nullptr;
            }
        }
        std::string dl(std::string folder, std::string query, std::string imgaeKey){
            Value *v = nullptr;
            //api using different url for artifacts
            if(folder == "artifacts") v = this->raw_link(query);
            else v = this->raw_link(folder, query);

            if(v != nullptr){
                std::string dl_url = this->dl_url + "/file/genshincard/" + folder + "/" + *v["images"][imgaeKey].asString();
            }
            else{
                std::string dl_url = this->dl_url + "/file/genshincard/" + "unknown.png";
            }
            return this->check(dl_url);
        }

    public:
        Reader reader;
        link(){
            cpr::Response r = cpr::Get(cpr::Url{"https://api.backblazeb2.com/b2api/v2/b2_authorize_account"},
                      cpr::Authentication{ APPLICATION_KEY_ID, APPLICATION_KEY, cpr::AuthMode::BASIC });
            reader.parse(r.text, value);
            this->dl_url = value["downloadUrl"].asString();
        }
        std::string demo_dl(){
            return this->dl_url + "/file/genshincard/ganyu.jng";
        }
        std::string artifact(std::string artifact_name, std::string type){
            //attempt to make our own assets
            //std::string dl_url = this->dl_url + "/file/genshincard/artifacts/" + artifact_name + ".png";
            return this->dl("artifacts", artifact_name, "name"+type);
        }
        std::string character(std::string character_name){
            return this->dl("characters", character_name, "namegachasplash");
        }
        std::string stats(std::string stat_name){ //change this to local
            return this->dl_url + "/file/genshincard/stats/" + stat_name + ".png";
        }
}