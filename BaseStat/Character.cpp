#include "Character.h"
#include "Artifacts.h"
#include "GlobalValue.h"
#include <iostream>
Character::Character(std::string name, int level, int rarity, int ascension, int constellation, std::tuple <int, int, int> talents)
{
    this->name = name;
    this->level = level;
    this->rarity = rarity;
    this->ascension = ascension;
    this->constellation = constellation;
    this->set_talent_level(std::get<0>(talents), std::get<1>(talents), std::get<2>(talents));
}
Character::~Character()
{
    std::cout<<"Character object: "<<name<<" destroyed."<<std::endl;
}

void Character::set_stat(std::string stat, double value){this->stats.at(stat) = value;}
double Character::get_stat(std::string stat){return this->stats.at(stat);}
std::string Character::cons_link(int cons){return root + "chars/" + this->name + "/cons_" + std::to_string(cons) + ".png";}
std::string Character::talent_link(std::string talent){return root + "chars/" + this->name + "/talent_" + talent + ".png";}
std::string Character::get_specialized(){return this->specialized;}
void Character::set_specialized(std::string spec){this->specialized = spec;}
void Character::set_talent_level(int _auto, int _skill, int _burst)
{
    talents["auto"] = std::pair<int, std::string >(_auto, this->talent_link("auto"));
    talents["skill"] = std::pair<int, std::string >(_skill, this->talent_link("skill"));
    talents["burst"] = std::pair<int, std::string>(_burst, this->talent_link("burst"));
}
void Character::printCharacter(){
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Level: "<<level<<std::endl;
    std::cout<<"Rarity: "<<rarity<<std::endl;
    std::cout<<"Ascension: "<<ascension<<std::endl;
    std::cout<<"Constellation: "<<constellation<<std::endl;
    std::cout<<"Auto: "<<talents["auto"].first<<std::endl;
    std::cout<<"Skill: "<<talents["skill"].first<<std::endl;
    std::cout<<"Burst: "<<talents["burst"].first<<std::endl;
    
    std::cout<<"Stats: "<<std::endl;
    for(auto& x: stats){
        std::cout<<x.first<<": "<<x.second<<std::endl;
    }
}
void Character::printArtifacts(){
    this->artifacts.print_artifacts();
    std::cout<<"Bonus artifact: "<<std::endl;
    auto bonus = this->artifacts.get_bonus2pc();
    for(auto& x: bonus){
        std::cout<<x.first<<": "<<x.second<<std::endl;
    }
}
void Character::set_artifacts(Artifacts artifacts){
    this->artifacts = artifacts;
}
void Character::set_artifact(Artifact artifact){
    this->artifacts.add_artifact(artifact);
}
void Character::set_weapon(Weapon weapon){
    this->weapon=weapon;
}
void Character::printWeapon(){
    this->weapon.printWeapon();
}
Artifacts Character::get_artifacts(){
    return this->artifacts;
}
