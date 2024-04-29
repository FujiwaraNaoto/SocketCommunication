FROM ubuntu:latest
# update, makeインストール,boostライブラリ，コンパイラg++のインストール

RUN apt-get update && \
    apt-get install -y g++ && \
    apt-get install -y libboost-all-dev && \
    apt-get install -y make && \
    rm -rf /var/lib/apt/lists/*

#ホストのsocket_cppディレクトリ内容をコンテナの作業ディレクトリ /appにコピー
COPY socket_cpp /app

WORKDIR /app

EXPOSE 31400


RUN chmod +x /app/start.sh

#シェルを用いてmakeでのビルドと実行を行う
ENTRYPOINT ["/bin/bash","/app/start.sh"]
