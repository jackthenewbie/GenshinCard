#Warn: This is quick install for local usage
SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
sudo apt-get update -y
sudo apt-get install -y python3.10 python3-pip git-all build-essential pkg-config `cat ${SCRIPTPATH}/dependencies`
git clone https://github.com/ImageMagick/ImageMagick.git "${SCRIPTPATH}/ImageMagick"
cd "${SCRIPTPATH}/ImageMagick" && ./configure CXX=g++
make
make install
git clone https://github.com/libcpr/cpr.git "${SCRIPTPATH}/cpr"
cd "${SCRIPTPATH}/cpr" && mkdir build && cd build
cmake "${SCRIPTPATH}/cpr" -DCPR_BUILD_TESTS=OFF
sudo make install