#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<boost/asio.hpp>
#include<array>


namespace asio=boost::asio;
using asio::ip::tcp;

const unsigned int port=31400;

int main(){


    try{

        asio::io_context io_context;
        tcp::endpoint endpoint=tcp::endpoint(tcp::v4(),port);
        tcp::acceptor acceptor(io_context,endpoint);
        std::cout<<"Endpoint IP address: "<<endpoint.address().to_string()<<std::endl;
        std::cout<<"Endpoint port: "<<endpoint.port()<<std::endl;

        std::cout<<"server is running on port "<<port<<std::endl;

        while (1)
        {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::cout<<"Client connected"<<std::endl;

            {//メッセージを受け取った処理
                std::array<char,1<<7> buf;
                boost::system::error_code error;
                
                size_t message_len=socket.read_some(asio::buffer(buf),error);
                //std::cout<<"message_len="<<message_len<<std::endl;
                for(size_t idx=0;idx<message_len;idx++){
                   std::cout<<buf[idx];
                }
                std::cout<<std::endl;

                if(error==asio::error::eof){
                    std::cout<<"Connection closed"<<std::endl;
                    
                }else if(error){
                    throw boost::system::system_error(error);
                }
                
                asio::write(socket,asio::buffer(buf,message_len));

            }
            /*
            std::string message="Hello from server\n";

            boost::system::error_code ignored_error;
            boost::asio::write(socket,boost::asio::buffer(message),ignored_error);
            */
        }
        
        
    }catch(std::exception e){
        std::cerr<<e.what()<<std::endl;
    }

    return 0;
}