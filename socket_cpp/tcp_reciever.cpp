#include<iostream>
#include<string>
#include<boost/asio.hpp>

namespace asio=boost::asio;
using asio::ip::tcp;

//const std::string target_address="127.0.0.1";

const unsigned int end_point_port=31400;

int main(){

    while(1){
        asio::io_service io_service;
        tcp::acceptor acc(io_service,tcp::endpoint(tcp::v4(),end_point_port));
        tcp::socket socket(io_service);

        //接続待機
        acc.accept(socket);

        //メッセージ受信
        asio::streambuf receive_buffer;
        boost::system::error_code error;
        asio::read(socket,receive_buffer,asio::transfer_all(),error);

        if(error && error!=asio::error::eof){
            std::cout<<"receive failed:"<<error.message()<<std::endl;
            break;
        }else{
            const char* data=asio::buffer_cast<const char*>(receive_buffer.data());
            std::cout<<data<<std::endl; 
        }

    }


}