g++ -std=c++2b `/home/pifordecoyer/code/cpp/GenshinCard/ImageMagick/bin/Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-g ./background.cpp \
-o background \
`/home/pifordecoyer/code/cpp/GenshinCard/ImageMagick/bin/Magick++-config --ldflags --libs` \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS