/*

g++ client.cpp -o client -lboost_system -pthread -std=c++17
*/
#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<boost/asio.hpp>
#include<array>

namespace asio=boost::asio;
using asio::ip::tcp;

const std::string target_address="127.0.0.1";
const unsigned int target_port=31400;

int main(){
    try{

        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        auto endpoints=resolver.resolve("localhost","31400");

        tcp::socket socket(io_context);
        boost::asio::connect(socket,endpoints);

        while (1)
        {
            std::array<char,128> buf;//サーバから送られるデータを読みこむ
            boost::system::error_code error;

            size_t len=socket.read_some(boost::asio::buffer(buf),error);

            if(error == boost::asio::error::eof)
                break;
            else if(error)
                throw boost::system::system_error(error);

            std::cout.write(buf.data(),len);

        }
        


        
    }catch(std::exception e){
        std::cerr<<e.what()<<std::endl;
    }

    return 0;
}