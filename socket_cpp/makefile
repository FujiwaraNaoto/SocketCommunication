#Makefile

#コンパイラの指定
CXX=g++

#
CXXFLAGS=-std=c++17 -pthread -lboost_system

#実行ファイル名
TARGET=tcp_server

#ソースファイル
SRC=tcp_server.cpp

#オブジェクトファイル
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)

# $@=ターゲット名,tcp_serverとなる
# $^=ターゲットの全ての依存関係の名前 とは言っても,OBJにはtcp_server.oしかない

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)


#オブジェクトファイルのビルド
# $< 依存関係の一番最初の名前　今回はserver.cppとなる
%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)


#make clean
clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
