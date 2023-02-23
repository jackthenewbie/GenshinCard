#include "Weapon.h"
#include "Stat.h"
#include "GlobalValue.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
Weapon::Weapon(std::string name, int level, int rarity, int ascension, int refinement){
    this->name = name;
    this->level = level;
    this->rarity = rarity;
    this->ascension = ascension;
    this->refinement = refinement;
}
void Weapon::set_main_stat(std::string stat, double value){
    try{
        this->stats.at(stat) = value;}
    catch(const std::out_of_range& e){
        std::cout<<"Insert stat unsuccessfully (Please see GOOD -"
        <<"Genshin Open Object Description keys). Abort"<<std::endl;
        return;
    }
    this->main_stat = stat;
}
void Weapon::set_sub_stat(std::string stat, double value){
    try{
        this->stats.at(stat) = value;}
    catch(const std::out_of_range& e){
        std::cout<<"Insert stat unsuccessfully (Please see GOOD -"
        <<"Genshin Open Object Description keys). Abort"<<std::endl;
        return;
    }
    this->sub_stat = stat;
}
void Weapon::printWeapon(){
    std::cout<<"Weapon: "<<this->name<<" "<<this->rarity<<"*"<<std::endl;
    std::cout<<"Main Stat: "<<this->main_stat<<" "<<this->stats.at(this->main_stat)<<std::endl;
    std::cout<<"Sub Stat: "<<this->sub_stat<<" "<<this->stats.at(this->sub_stat)<<std::endl;
}
std::string Weapon::get_main_stat(){return this->main_stat;}
std::string Weapon::get_sub_stat(){return this->sub_stat;}
double Weapon::get_main_stat(bool value){return this->stats.at(this->main_stat);}
double Weapon::get_sub_stat(bool value){return this->stats.at(this->sub_stat);}