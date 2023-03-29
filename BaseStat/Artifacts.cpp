#include "Character.h"
#include "GlobalValue.h"
#include "Artifact.h"
#include "Artifacts.h"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <map>
#include <set>
#define MAX_ARTIFACT 5
using namespace Json;
void Artifacts::add_artifact(Artifact artifact){
    if(this->artifacts.size() == MAX_ARTIFACT){
        std::cout<<"Max artifact reached. Abort"<<std::endl;
        return;
    }
    else if(artifact_sets.find(artifact.get_set()) == artifact_sets.end()){
        std::cout<<"Artifact set not found. Abort"<<std::endl;
        return;
    }
    artifacts.push_back(artifact);
}
void Artifacts::remove_artifact(std::string type){
    if(this->artifacts.size() == 0){std::cout<<"No artifact to remove. Abort"<<std::endl;return;}
    for(std::vector<Artifact>::iterator it = this->artifacts.begin(); it != this->artifacts.end(); it++){
        if(it->get_type() == type){
            this->artifacts.erase(it);
            std::cout<<"Artifact removed"<<std::endl;
            return;
        }
    }
    std::cout<<"Artifact not found. Abort"<<std::endl;
}
void Artifacts::valid(){
    for(auto artifact: this->artifacts){
        for(auto type: artifact_types)
            for(auto set: artifact_sets)
                if(!(artifact.get_type() != type || artifact.get_set() != set)){
                    std::cout<<"Invalid artifact type. Now trying to remove"<<artifact.get_type()<<std::endl;
                    remove_artifact(artifact.get_type());
                }
    }
}
void Artifacts::print_artifacts(){
    for(auto artifact: this->artifacts){
        artifact.print_artifact();
    }
}
std::string Artifacts::descp2pc(std::string set){
    Reader rd;
    Value vl;
    cpr::Response r = cpr::Get(cpr::Url{"https://genshin-db-api.vercel.app/api/artifacts?query=" + set});
    rd.parse(r.text, vl);
    return vl["2pc"].asString();
}
double specialStat(std::string stat, double value){
    if(stat.at(stat.length()-1) == '_') return value/double(100);
    return value;
}
void Artifacts::cal_bonus(){
    this->bonus2pc.clear();
    std::map <std::string, int> bonus;
    for(auto artifact: this->artifacts){
        if(bonus.count(artifact.get_set())){
            bonus.at(artifact.get_set()) += 1;
        }
        else{
            bonus.insert(std::pair<std::string, int>(artifact.get_set(), 1));
        }
    }
    auto extractInt = [](std::string s){
        std::string num = "";
        for(auto c: s){
            if(isdigit(c)){
                num += c;
            }
        }
        return std::stoi(num);
    };
    
    for(const auto& set_: bonus){
        if(set_.second >= 2){
            std::string desc = this->descp2pc(set_.first);
            std::string bonus_stat = bonus_from(desc);
            if(str_util::is_string_equal(bonus_stat, "Undefined")) continue;
            this->bonus2pc.insert(std::pair<std::string, double>(bonus_from(desc), specialStat(bonus_from(desc),extractInt(desc)))); //desc could be wrong
        }
    }
}
std::map<std::string, double> Artifacts::get_bonus2pc(){
    this->cal_bonus();
    return this->bonus2pc;
}
std::vector<std::string> Artifacts::artifacts_link(){
    std::vector<std::string> artifacts_link;
    for(auto artifact: this->artifacts){
        artifacts_link.push_back(artifact.get_link());
    }
    return artifacts_link;
}
std::vector<Artifact> Artifacts::get_artifacts(){
    return this->artifacts;
}