#ifndef STAT_H
#define STAT_H
#include <string>
#include <map>
class Stat{
    protected:
        int level, rarity, ascension;
        std::string name;
        std::map<std::string, double> stats{
        {"hp_", 0}
        ,{"hp", 0}
        ,{"atk_", 0}
        ,{"atk", 0}
        ,{"def_", 0}
        ,{"def", 0}
        ,{"eleMas", 0}
        ,{"heal_", 0}
        ,{"enerRech_", 0}
        ,{"critRate_", 0}
        ,{"critDMG_", 0}
        ,{"physical_dmg_", 0}
        ,{"anemo_dmg_", 0}
        ,{"cryo_dmg_", 0}
        ,{"dendro_dmg_", 0}
        ,{"electro_dmg_", 0}
        ,{"geo_dmg_", 0}
        ,{"hydro_dmg_", 0}
        ,{"pyro_dmg_", 0}};
    public:
        std::string stat_link(std::string);
};
#endif