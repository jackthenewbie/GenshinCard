#include <cpr/cpr.h>
#include "cprdemo.h"
#include <iostream>

int cprdemo::demo() {
    cpr::Response r = cpr::Get(cpr::Url{"https://genshin-db-api.vercel.app/api/stats?folder=characters&query=ganyu&level=80+&dumpResult=true"});
    std::cout << r.status_code;                  // 200
    std::cout << r.header["content-type"];       // application/json; charset=utf-8
    std::cout << r.text;                         // JSON text string
    return 0;
}
