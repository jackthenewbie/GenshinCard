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
        void drawBasic(int, int, int);
        void drawBonus(int, int, int, int, std::string, std::vector<std::string> displayStat = {}, bool skipBasic = true); //from artifacts
        void drawWeapon(int ximg, int yimg, int xstat, int xval, int y, int spacey);
        void drawArtifact(int ximg, int yimg, int xstat, int xval, int y, int spacey, int icon_size=100);
        void drawTalents(int, int, int);
        void drawCons(int, int, int);
        std::vector<Drawable> get_drawList();

};       
#endif