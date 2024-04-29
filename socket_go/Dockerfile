FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y golang-go && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* 

#ホストのこのディレクトリ内容をコンテナの作業ディレクトリ /appにコピー
COPY socket_go /app

#作業ディレクトリ
WORKDIR /app

ENV PATH $PATH:/usr/local/go/bin

EXPOSE 31400

#ports:
#  - "31401:31400"

CMD ["go","run","/app/client.go"]
