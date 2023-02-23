#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <set>
namespace expr_algo{
    template <typename T>
    std::set<T> vector2set(std::vector<T> vec){
        std::set<T> set;
        for(auto i : vec){
            set.insert(i);
        }
        return set;
    }
    template <typename T>
    std::vector<T> set2vector(std::set<T> set){
        std::vector<T> vec;
        for(auto i : set){
            vec.push_back(i);
        }
        return vec;
    }
    template <typename T> //remove duplicate elements in vector
    void remove_duplicate(std::vector<T>& vec){
        std::set<T> set;
        for(auto i : vec){
            set.insert(i);
        }
        vec=set2vector(set);
    }
}