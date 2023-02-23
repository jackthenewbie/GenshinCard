#pragma once
#ifndef STR_H
#define STR_H
#include <string>
namespace str_util{
    std::string toString(bool b); //convert bool value to string
    //compare two string, ignore case
    bool is_string_contain(const std::string& str1, const std::string& str2);
    bool is_string_equal(const std::string& str1, const std::string& str2, bool caseSensitive = false);
    std::string rm0tail(std::string str); //remove 0 tail
};
#endif