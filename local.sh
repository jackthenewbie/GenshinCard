g++ -std=c++2b `/home/pifordecoyer/code/cpp/GenshinCard/ImageMagick/bin/Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-I/home/pifordecoyer/code/cpp/GenshinCard/include \
-I/usr/include/python3.10/ \
-g ./*.cpp ./DataProcess/*.cpp ./BaseStat/*.cpp ./Util/*.cpp ./Image/*.cpp \
-o GenshinCard \
`/home/pifordecoyer/code/cpp/GenshinCard/ImageMagick/bin/Magick++-config --ldflags --libs` `python3.10-config --ldflags --embed` \
-ljsoncpp -l:libboost_python310.so -lcpr \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS \
-DBOOST_ALLOW_DEPRECATED_HEADERS