#include "Stat.h"
#include "GlobalValue.h"
#include <string>
#include <iostream>
std::string Stat::stat_link(std::string stat){
    return root + "stats/" + stat + ".png";
}