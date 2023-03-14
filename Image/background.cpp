#include <Magick++.h>
#include <cmath>
#include <iostream>
#include <vector>
#define BASIC_STAT_SIZE 23
#define FONT "Times-New-Roman"
using namespace std; 
using namespace Magick;
void annotate(Image* image){
  image->font("Times-New-Roman");
  try { 
    // Read a file into image object 
    ColorRGB color(255,255,255);
    //image->fontPointsize(23);
    image->strokeColor(color);
    image->strokeWidth(0.00000001);
    image->fillColor(color);
    image->annotate("1999 HP", "+800+195");
    
  } 
  catch( Exception &error_ ) 
  { 
    cout << "Caught exception: " << error_.what() << endl; 
    //return 1; 
  } 
}
void drawableText(Image* image){
  std::vector<Magick::Drawable> drawList;
  image->font("Times-New-Roman");
  try {
    drawList.push_back(DrawableFont("Times-New-Roman"));
    drawList.push_back(DrawableText(820, 212,"1999"));
    drawList.push_back(DrawableFillColor("white"));
    drawList.push_back(DrawablePointSize(26));
    drawList.push_back(DrawableText(549, 562+58,"Cryo DMG Bonus"));
    //transparent cyro dmg bonus
    Image cryo("cryo_dmg_.png");
    //cryo.alpha(true);
    //cryo.transparent(Color(cryo.pixelColor(1,1)));
    int font_size = 26;
    cryo.resize(Geometry(font_size, font_size));
    Geometry cryo_ = cryo.size();
    int width_from_stat = int(round(font_size/3));
    drawList.push_back(DrawableCompositeImage(549-cryo_.width() - width_from_stat, 562+58-font_size+int(round(font_size/4)), 0, 0, cryo, OverCompositeOp));
    //drawList.push_back(DrawableFillColor("white"));
    //image->fontPointsize(23);
    //image->strokeColor(color);
    //image->fillColor(color);
    image->draw(drawList);
    //image->pixelColor(549, 212, "red");
    
  } 
  catch( Exception &error_ ) 
  { 
    cout << "Caught exception: " << error_.what() << endl; 
    //return 1; 
  } 
} 
void writeStatKey(Image image, std::string key, int x, int y){
    image.annotate(key, "+x+y", EastGravity);
}
void drawWeapon(Image *image, int size){
  std::vector<Magick::Drawable> drawList;
  image->font("Times-New-Roman");
  try{
    Image wp("UI_EquipIcon_Bow_Amos_Awaken#63040.png");
    wp.resize(Geometry(size,size));
    drawList.push_back(DrawableCompositeImage(470, 20, 0, 0, wp, OverCompositeOp));
    image->draw(drawList);
  }catch( Exception &error_ ) 
  { 
    cout << "Caught exception: " << error_.what() << endl; 
    //return 1; 
  }
}
//int main(int argc, char **argv) 
int mainx(int argc, char **argv) 
{ 
  InitializeMagick(*argv);
  DrawableText demo(0,0,"1999 HP");
  Image image;
  image.read(argv[1]);
  //annotate(&image);
  drawWeapon(&image, std::stoi(argv[2]));
  image.write("result.png");
  
  return 0; 
}

/*int main(int argc,char **argv) 
{ 
  InitializeMagick(*argv);

  // Construct the image object. Seperating image construction from the 
  // the read operation ensures that a failure to read the image file 
  // doesn't render the image object useless. 
  Image image;
  try { 
    // Read a file into image object 
    image.read("/home/pifordecoyer/code/cpp/GenshinCard/MishaOsipov.png");

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.crop( Geometry(100,100, 100, 100) );

    // Write the image to a file 
    image.write( "logo.png" ); 
  } 
  catch( Exception &error_ ) 
    { 
      cout << "Caught exception: " << error_.what() << endl; 
      //return 1; 
    } 
  return 0; 
}*/