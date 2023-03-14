g++ -std=c++20 `Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-g ./background.cpp \
-o background \
`Magick++-config --ldflags --libs` \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS