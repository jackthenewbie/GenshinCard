FROM ubuntu:GenshinCard
ENV DEBIAN_FRONTEND noninteractive
ENV PKG_CONFIG_PATH /usr/local/lib/pkgconfig
ENV LD_LIBRARY_PATH /usr/local/lib
ENV GENSHINCARD_PY_PATH /usr/src/bot
WORKDIR /app/GenshinCard
COPY . .
RUN pip3 install pillow python-dotenv && /bin/bash locald.sh