python3 migrate_path.py
g++ -g -shared -fPIC -std=c++2b `Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-I/app/GenshinCard/include \
-I/usr/include/python3.10/ \
-g ./*.cpp ./DataProcess/*.cpp ./BaseStat/*.cpp ./Util/*.cpp ./Image/*.cpp \
-o $GENSHINCARD_PY_PATH/GenshinCard.so \
`Magick++-config --ldflags --libs` `python3.10-config --ldflags --embed` \
-ljsoncpp -l:libboost_python310.so -lcpr \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS \
-Wno-deprecated-declarations \
-DBOOST_ALLOW_DEPRECATED_HEADERS
ldconfig
echo "Build complete. Copying assets to $GENSHINCARD_PY_PATH"
sleep 1d