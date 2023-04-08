FROM ubuntu:GenshinCard
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get install -y curl
WORKDIR /app/GenshinCard
COPY . .
WORKDIR /app/GenshinCard
ENTRYPOINT ["/bin/bash"]
CMD ["locald.sh"]