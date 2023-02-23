#include "Talents.h"
#include "GlobalValue.h"
#include <string>
#include <vector>
//char_name must be match with folder name

Talents::Talents(std::string char_name, int auto_, int skill_, int burst_){
    talents.clear();
    this->talents.push_back(std::make_pair(auto_, this->get_link(char_name, "auto")));
    this->talents.push_back(std::make_pair(skill_, this->get_link(char_name, "skill")));
    this->talents.push_back(std::make_pair(burst_, this->get_link(char_name, "burst")));
}
std::string Talents::get_link(std::string char_name, std::string type){
    return root + "char/" + char_name + "/"+type+".png"; //need fix
}
void Talents::set_talents(std::string char_name, int auto_, int skill_, int burst_){
    Talents(char_name, auto_, skill_, burst_);
}
Talents::Talents(){
    talents.clear();
    this->set_talents("",1,1,1);
}