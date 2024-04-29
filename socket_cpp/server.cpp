#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<boost/asio.hpp>
#include<array>

namespace asio=boost::asio;
using asio::ip::tcp;

const std::string target_address="127.0.0.1";
const unsigned int port=31400;

int main(){
    try{

        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context,tcp::endpoint(tcp::v4(),port));

        std::cout<<"server is running on port "<<port<<std::endl;

        while (1)
        {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::string message="Hello from server\n";

            boost::system::error_code ignored_error;
            boost::asio::write(socket,boost::asio::buffer(message),ignored_error);
        }
        
        
    }catch(std::exception e){
        std::cerr<<e.what()<<std::endl;
    }

    return 0;
}