FROM ubuntu:22.04
RUN apt update -y \
    && apt upgrade -y \
    && apt install -y git gcc g++ cmake libjsoncpp-dev uuid-dev zlib1g-dev openssl libssl-dev

RUN cd /opt \
    && git clone https://github.com/drogonframework/drogon \
    && cd drogon \ 
    && git submodule update --init \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install

COPY . /app
RUN cd /app \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make
WORKDIR /app
CMD ["/app/build/MachiKoroCPP"]