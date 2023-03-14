#include "GlobalValue.h"
#include "str.h"
#include <string>
#include <iostream>
using namespace str_util;
std::string verbose(std::string stat, std::vector<std::string> searchv, std::vector<std::string> returnv){
    for(unsigned int i = 0; i < searchv.size(); i++){
        if(is_string_equal(stat, searchv.at(i), true)) return returnv.at(i);
    }
    return "Undefied";
}
std::string get_bonus(std::string bonus){
    //pyro res, cryo res, hydro res, electro res, anemo res, geo res, physical res
    //healing effective, shield strength, all res
    return verbose(bonus, verbose_stat_api, verbose_stat_GOOD); 
}
std::string display(std::string stat){
    return verbose(stat, verbose_stat_GOOD, verbose_stat_display);
}