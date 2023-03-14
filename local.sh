g++ -std=c++20 `Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-I/home/ser3_decoyer/repo/GenshinCard/include \
-I/usr/include/python3.9/ \
-g ./*.cpp ./DataProcess/*.cpp ./BaseStat/*.cpp ./Util/*.cpp ./Image/*.cpp \
-o GenshinCard \
`Magick++-config --ldflags --libs` `python3.9-config --ldflags --embed` \
-ljsoncpp -l:libboost_python39.so -lcpr \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS \
-Wno-deprecated-declarations \
-DBOOST_ALLOW_DEPRECATED_HEADERS