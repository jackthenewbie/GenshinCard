FROM ubuntu:GenshinCard
ENV DEBIAN_FRONTEND noninteractive
WORKDIR /app/GenshinCard
COPY . .
WORKDIR /app/GenshinCard/Image
ENTRYPOINT ["/bin/bash"]
CMD ["/app/GenshinCard/Image/locald.sh"]