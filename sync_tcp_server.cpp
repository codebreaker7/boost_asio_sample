#include "sync_tcp_server.h"

#include <boost/array.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

sync_tcp_server::sync_tcp_server(io_context &context):
    basic_server(context)
{
    acceptor = new tcp::acceptor(context, tcp::endpoint(tcp::v4(), 33333));
    sync_serv_socket = new tcp::socket(context);
}

void sync_tcp_server::run_server() {
    boost::array<char, 128> readbuf;

    // to test delayed acception
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    acceptor->accept(*sync_serv_socket);

    sync_serv_socket->read_some(buffer(readbuf));
    if (std::strcmp(readbuf.data(), "HELLO") == 0) {
        cout << "Received " << readbuf.data() << endl;
        sync_serv_socket->write_some(buffer("HELLO FROM SERVER"));
        sync_serv_socket->close();
    }
}

