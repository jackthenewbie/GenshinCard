#pragma once
#ifndef ARTIFACTS_H
#define ARTIFACTS_H
#include "Artifact.h"
#include "Stat.h"
#include <string>
#include <vector>
#include <map>
class Artifacts : Stat{ //Artifact manager
    private:
        std::map<std::string, double> bonus2pc;
        //size 5 vector
        std::vector<Artifact> artifacts;
    public:
        void add_artifact(Artifact artifact);
        void remove_artifact(std::string type);
        void valid();
        void print_artifacts();
        void cal_bonus();
        std::string descp2pc(std::string set);
        std::map<std::string, double> get_bonus2pc();
        std::vector<std::string> artifacts_link();
        std::vector<Artifact> get_artifacts();
};  
#endif