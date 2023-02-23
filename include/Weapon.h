#ifndef WEAPON_H
#define WEAPON_H
#include "Stat.h"
#include "GlobalValue.h"
#include <string>
#include <set>
#include <map>
class Weapon : Stat{
    private:
        std::string main_stat,sub_stat; //already have rarity, level
        int refinement=1;
    public:
        Weapon(std::string name="", int level=0, int rarity=0, int ascension=0, int refinement=0);
        void set_main_stat(std::string stat, double value);
        void set_sub_stat(std::string stat, double value);
        std::string get_main_stat();
        double get_main_stat(bool);
        std::string get_sub_stat();
        double get_sub_stat(bool);
        int get_rarity(){return this->rarity;};
        int get_level(){return this->level;};
        int get_refinement(){return this->refinement;};
        std::string get_name(){return this->name;};
        std::string weapon_link(){return root + "weapons/" + this->name + ".png";};
        void printWeapon();
        void icon(int, int); //base from a point,  must be base on a text

};
#endif
