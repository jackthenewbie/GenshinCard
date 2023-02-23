#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include "demoJsoncpp.h"
using namespace std;
using namespace Json;
void in(){
    ifstream ifs(".vscode/tasks.json");
    Reader reader;
    Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    cout << obj["tasks"][0]["args"] << endl;
}