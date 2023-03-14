/usr/bin/g++ -g -shared -fPIC -std=c++2b \
`/app/GenshinCard/ImageMagick/bin/Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always -I/app/GenshinCard/include -I/usr/include/python3.9/ \
/app/GenshinCard/*.cpp /app/GenshinCard/DataProcess/*.cpp -o /app/GenshinCard/GenshinCard.so \
`/app/GenshinCard/ImageMagick/bin/Magick++-config --ldflags --libs` `python3.9-config --ldflags --embed` \
 -ljsoncpp -l:libboost_python310.so -lcpr
ldconfig
echo "Build complete."
sleep 1d