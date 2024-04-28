#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<boost/asio.hpp>

namespace asio=boost::asio;
using asio::ip::tcp;

const std::string target_address="127.0.0.1";
const unsigned int target_port=31400;

int main(){
    asio::io_service io_service;
    tcp::socket socket(io_service);
    
    socket.connect(tcp::endpoint(asio::ip::address::from_string(target_address),target_port));

    while(1){
        const std::string message="hello";
        boost::system::error_code error;
        asio::write(socket,asio::buffer(message),error);

        if(error){
            std::cout<<"send failed"<<error.message()<<std::endl;
            break;
        }else{
            std::cout<<"send correct"<<std::endl;      
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));//wait for 1 sec

    }
}