#ifndef CHARACTER_H
#define CHARACTER_H
#include "Stat.h"
#include "Weapon.h"
#include "Artifacts.h"
#include "Talents.h"
#include <iostream>
#include <string>
#include <tuple>
#include <map>
class Character : protected Stat{
    protected:
        Artifacts artifacts;
        Weapon weapon;
        int constellation;
        std::string specialized;
        std::map<std::string, int> talents;
    public:
        Character(std::string name="", int level=0, int rarity=0, int ascension=0, int constellation=0, std::tuple <int, int, int> talents=std::make_tuple(0, 0, 0));
        virtual ~Character();
        Artifacts get_artifacts();
        Weapon get_weapon(){return this->weapon;};
        std::string cons_link(int);
        std::string talent_link(std::string); //talent icon
        std::string get_specialized();
        void set_specialized(std::string);
        void set_stat(std::string, double);
        double get_stat(std::string);
        void set_talent_level(int, int, int);
        void set_artifacts(Artifacts);
        void set_artifact(Artifact);
        void set_weapon(Weapon);
        void printCharacter();
        void printArtifacts();
        void printWeapon();
        
};
#endif