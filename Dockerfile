FROM ubuntu:GenshinCard
ENV DEBIAN_FRONTEND noninteractive
WORKDIR /app/GenshinCard
COPY . .
RUN pip3 install pillow
ENTRYPOINT ["/bin/bash"]
CMD ["locald.sh"]