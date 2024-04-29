#! /bin/bash

SOURCE="tcp_server.cpp"

OUPUT="tcp_server"

#make
g++  -std=c++17 -pthread $SOURCE -o $OUTPUT -lboost_system

if [ $? -eq 0 ]; then
    echo "success compile"
    ./$OUPUT
else
    echo "failed to compile"
fi
