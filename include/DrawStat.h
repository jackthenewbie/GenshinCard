#ifndef DRAWSTAT_H
#define DRAWSTAT_H
#include <vector>
#include <string>
#include <map>
#include <Magick++.h>
#include "Character.h"
using namespace Magick;
class DrawStat : Stat{ //of char and weapon, this class just create drawlist
    private:
        Character* character;
        std::vector<Drawable> drawList;
        bool calculate = false;
    public:
        DrawStat(Character* character);
        void calculateAll();
        void iconToDrawlist(std::string icon, int x, int y);
        void drawBasic(int x, int y, int space);
        void drawBonus(int xstat, int xval, int y, int spacey, int xicon, int yicon, int icon_size, std::string, std::vector<std::string> displayStat = {}, bool skipBasic = true); //from artifacts
        void drawWeapon(int ximg, 
                          int yimg,
                          int xname,
                          int yname,
                          int name_size, 
                          int xstat, 
                          int ystat,
                          int mainstat_size,
                          int xval, 
                          int yval,
                          int spacex, 
                          int spacey, 
                          int icon_size);
        void drawArtifact(int ximg, 
                           int yimg,
                           int FONT_SIZE_name,
                           int xname,
                           int yname,
                           int FONT_SIZE_mainstat, 
                           int xmainstat,
                           int ymainstat,
                           int xmainval,
                           int ymainval,
                           int mainstat_size,
                           int FONT_SIZE_substat, 
                           int xsubstat,
                           int ysubstat,
                           int xsubval,
                           int ysubval,
                           int substat_size, 
                           int spacesubx,
                           int spacesuby, 
                           int icon_size);
        void drawTalents(int ximg,
                           int yimg,
                           int spacex,
                           int spacey,
                           int icon_size,
                           int xframe,
                           int yframe,
                           int frame_size);
        Image drawBackground(std::string ground_back, int xsplash, int ysplash, std::string ground_front, int shiftFront);
        void drawCons(int, int, int);
        std::vector<Drawable> get_drawList();

};       
#endif