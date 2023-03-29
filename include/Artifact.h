#ifndef ARTIFACT_H
#define ARTIFACT_H
#include "Stat.h"
#include <string>
#include <set>
#include <map>

class Artifact : protected Stat{
    private:
        std::string main_stat; //already have rarity, level
        std::set<std::string> sub_stats;
        std::string type, set; //set name, and type
    public:
        Artifact(std::string setName, std::string type, int rarity, int level);
        void set_main_stat(std::string stat, double value);
        void set_sub_stat(std::map<std::string, double> stats);
        std::string get_main_stat();
        double get_main_stat(bool);
        std::set<std::string> *get_sub_stats();
        double get_sub_stat(std::string);
        std::string get_type();
        std::string get_set();
        std::string get_link();
        void print_artifact();
};
#endif