g++ -std=c++2b `Magick++-config --cxxflags --cppflags` \
-fdiagnostics-color=always \
-g ./*.cpp \
-o background \
`Magick++-config --ldflags --libs` \
-DBOOST_BIND_GLOBAL_PLACEHOLDERS
./background TOP.png AvantGarde-Book
sleep 1d