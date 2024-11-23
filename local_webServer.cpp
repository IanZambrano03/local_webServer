#include <asio.hpp>
#include <iostream>

int main()
{
    //WEB SERVER (ATTEMPT 1 / DAY 1 / 11/22/2024
try
{
    const char* inet_IP = "127.0.0.1";
    unsigned short port = 80;

    asio::ip::tcp::endpoint endpoint(asio::ip::address::from_string(inet_IP),port);

    asio::io_context io_context;

    asio::ip::tcp::acceptor TCP_acceptor(io_context, endpoint);

    std::cout << "Server is on, and listening on " << inet_IP << ":" << port << "\n";
    std::cout << "--------------------------------------------------------------> \n";

    asio::ip::tcp::socket socket(io_context);
    TCP_acceptor.accept(socket);

    std::string SERVERMESSAGE = "Hello there, I am able to listen to connections, accept connections ! \n";
    asio::write(socket, asio::buffer(SERVERMESSAGE));

    socket.close();
}
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
return 0;
}
