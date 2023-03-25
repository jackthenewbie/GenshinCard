#ifndef IMAGE_H
#define IMAGE_H
#include "str.h"
#include "Artifact.h"
#include "GlobalValue.h"
std::string artifact(Artifact *artifact){
    return root + "artifacts/" + artifact->get_set() + "/" + artifact->get_type + ".png";
}
std::string stat(std::string stat){
    return root + "stats/" + stat + ".png";
}
#endif