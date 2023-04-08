#ifndef INTERPRET_H
#define INTERPRET_H
#include "Character.h"
#include <string>
#include <Magick++.h>
#include <jsoncpp/json/json.h>
#include <map>
#include <set>
#include <string>
#include <queue>
using namespace std;
using namespace Json;
class Interpreter
{
    private:
        Reader reader;
        Value good_json;
        Value target_json;
        //blob pointer
        std::queue<Magick::Image*> finished_images;
        //std::map<std::pair<Value, Value>,Character> characters;
        std::map<std::vector<Value>,Character> characters;
        /*
          +first Value is from GOOD_JSON (partial) aka good_json, 
          +second Value is from scrap api (see ganyuApi.json or heizou for ex) 
           aka target_json (refresh every call, dont use)
           ext: testing advance use case
        */
    public:
        Interpreter(const char *filePath);
        Interpreter(std::string data);
        ~Interpreter();
        void set_good_json(Value good_json);
        std::queue<Magick::Image*> *get_finished_images(){return &this->finished_images;};
        Value Good_json();
        void Target_json(); //data from api & good_json -- api is 1, good_json(partial) is 0
        Value getPlainStat(std::string name, int level, int ascension, bool dumpResult);
        void printChars();
        void printArtifacts();
        void print();
        void igniteChars(std::set<std::string> names);
        void baseStats();
        void weaponStats();
        void igniteArtifacts();
        void drawBasic();
        std::string as2sign(int, int);
        double specialStat(std::string, double);
        Value api(std::string folder, std::string query, int level, std::string sign, bool dumpResult);
};

#endif