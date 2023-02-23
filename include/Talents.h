#ifndef TALENTS_H
#define TALENTS_H
#include <vector>
#include <string>
class Talents{
    private:
        std::vector<std::pair<int, std::string>> talents;
    public:
        Talents();
        Talents(std::string, int auto_, int skill_, int burst_);
        int get_auto_level();
        int get_skill_level();
        int get_burst_level();
        std::string get_link(std::string, std::string);
        void set_talents(std::string, int, int, int);
};
#endif