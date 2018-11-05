#include <iostream>
#include <boost/array.hpp>
#include "sync_tcp_client.h"

using namespace std;

sync_tcp_client::sync_tcp_client(io_context &context):
    basic_client(context), sync_socket(context)
{

}

void sync_tcp_client::do_work() {
    boost::system::error_code ec;
    boost::array<char, 1024> readbuf;

    tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 33333);
    sync_socket.connect(ep, ec);
    if (ec) {
        cerr << "Problem with connection" << endl;
        return;
    }
    // write start message
    sync_socket.write_some(buffer("HELLO"), ec);
    if (ec) {
        cerr << "Cannot write data!" << endl;
        return;
    }
    // read response data
    sync_socket.read_some(buffer(readbuf));
    cout << readbuf.data();
    while (sync_socket.available()) {
        sync_socket.read_some(buffer(readbuf));
        cout << readbuf.data();
    }
    cout << endl;
    cout << "Session successfully closed" << endl;
    sync_socket.close();
}

