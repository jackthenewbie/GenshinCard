#include "demoJsoncpp.h"
#include "interpret.h"
#include "Character.h" 
#include "cprdemo.h"
#include "DrawStat.h"
#include <boost/python.hpp>
#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <set>
//int main(int argc, const char* args[]);
//int pyMain(boost::python::str fP, boost::python::str n){
int main();
int pyMain(){
    //char const *filePath =boost::python::extract<char const*>(fP);
    //char const *name =boost::python::extract<char const*>(n);
    //const char* args[] = {"call from py",filePath, name};
    return main();
}
/**
 * @brief Main1 function: for executing program directly
 * 
 * @param args consist of json file path and character name
 * @return int 0 for success
 */
int main1(const char* args[]){
    
    Interpreter *i = new Interpreter(args[1]);//this is wrong btw
    std::cout<<"Args[2]--:"<<args[2]<<std::endl;
    std::cout << "Hello World!" << std::endl;
    //i->findChar(args[2]);
    delete i;
    return 0;
}
/**
 * @brief Main2 function: for executing program from direct input
 * 
 * @param args consist of json as string 
 * @return int 0 for success
*/
int main2(const char *good_json, std::set<std::string> names){
    Interpreter *i = new Interpreter(good_json);
    std::cout << "Hello World! from main2" << std::endl;
    i->igniteChars(names);
    //i->Target_json();
    //i->printChars();
    i->baseStats();
    i->igniteArtifacts();
    //i->weaponStats();
    i->print();
    i->drawBasic();
    delete i;
    return 0;
}
//int main(int argc, const char* args[]){
int main(){
    //if(!strcmp(args[2],"SHELL=/bin/bash")) std::cout<<"No args, prob debugging\n";
    //else return main1(args);
    //cpr::Response r = cpr::Get(cpr::Url{"https://genshin-db-api.vercel.app/api/stats?folder=characters&query=ganyu&level=80+&dumpResult=true"});
    return main2("data.json", {"ganyu"});
   
}
BOOST_PYTHON_MODULE(GenshinCard){
    boost::python::def("main", pyMain);
}