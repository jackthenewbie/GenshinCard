#include "str.h"
#include <string>
namespace str_util{
    std::string toString(bool b){
        return b ? "true" : "false";
    }
    bool is_string_equal(const std::string& str1, const std::string& str2, bool caseSensitive)
    {
        if(!caseSensitive) 
        return str1.size() == str2.size() && 
        std::equal(str1.begin(), str1.end(), str2.begin(), 
        [](auto a, auto b){return std::tolower(a)==std::tolower(b);});

        else return str1.size() == str2.size() && 
        std::equal(str1.begin(), str1.end(), str2.begin(), 
        [](auto a, auto b){return a==b;});
    }
    bool is_string_contain(const std::string& str1, const std::string& str2)
    {
        return str1.find(str2) != std::string::npos;
    }
    std::string rm0tail(std::string str){
        str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
        str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
        return str;
    }
}