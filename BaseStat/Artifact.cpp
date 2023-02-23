#include "Character.h"
#include "GlobalValue.h"
#include "Artifact.h"
#include "Artifacts.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MAX_ARTIFACT 5
Artifact::Artifact(std::string setName, std::string type, int rarity, int level){
    this->set = setName;
    this->type = type;
    this->rarity = rarity;
    this->level = level;
}
void Artifact::set_main_stat(std::string stat, double value){
    try{
        this->stats.at(stat) = value;}
    catch(const std::out_of_range& e){
        std::cout<<"Insert stat unsuccessfully (Please see GOOD -"
        <<"Genshin Open Object Description keys). Abort"<<std::endl;
        return;
    }
    this->main_stat = stat;
}
void Artifact::set_sub_stat(std::map<std::string, double> stats){
    for(auto stat: stats){
        try{
            this->stats.at(stat.first) = stat.second;
            this->sub_stats.insert(stat.first);}
        catch(const std::out_of_range& e){
            std::cout<<"Insert stat unsuccessfully (Please see GOOD -"
            <<"Genshin Open Object Description keys). Abort"<<std::endl;
            return;
        }
    }
}
std::string Artifact::get_main_stat(){return this->main_stat;}
double Artifact::get_main_stat(bool stat){return this->stats.at(this->main_stat);}
std::set<std::string> Artifact::get_sub_stats(){return this->sub_stats;}
double Artifact::get_sub_stat(std::string stat){return this->stats.at(stat);}
std::string Artifact::get_type(){return this->type;}
std::string Artifact::get_link(){return root + "artifact/" + this->set + "/" + this->type + ".png";}
std::string Artifact::get_set(){return this->set;}
void Artifact::print_artifact(){
    std::cout<<"Artifact: "<<this->set<<" "<<this->type<<" "<<this->rarity<<"*"<<std::endl;
    std::cout<<"Main Stat: "<<this->main_stat<<" "<<this->stats.at(this->main_stat)<<std::endl;
    std::cout<<"Sub Stats: "<<std::endl;
    for(auto stat: this->sub_stats){
        std::cout<<stat<<" "<<this->stats.at(stat)<<std::endl;
    }
}