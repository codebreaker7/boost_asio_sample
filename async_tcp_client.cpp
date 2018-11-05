#include "async_tcp_client.h"
#include <boost/bind.hpp>
#include <iostream>

using namespace std;

async_tcp_client::async_tcp_client(io_context & context):
    basic_client(context), async_socket(context)
{

}

void async_tcp_client::connect_handler(const boost::system::error_code &e) {
    cout << "Successful connection" << endl;
    async_socket.async_write_some(buffer("HELLO"), boost::bind(&async_tcp_client::write_handler, this,
                                                               boost::asio::placeholders::error,
                                                               boost::asio::placeholders::bytes_transferred));
}

void async_tcp_client::write_handler(const boost::system::error_code &e, size_t written) {
    cout << "Written " << written << " bytes" << endl;
    async_socket.async_read_some(buffer(cbuf), boost::bind(&async_tcp_client::read_handler, this,
                                                           boost::asio::placeholders::error,
                                                           boost::asio::placeholders::bytes_transferred));
}

void async_tcp_client::read_handler(const boost::system::error_code &e, size_t transferred) {
    cout << "Received " << transferred << endl;
    cout.write(cbuf, transferred);
    async_socket.close();
}

void async_tcp_client::do_work() {
    tcp::endpoint ep(address::from_string("127.0.0.1"), 33333);

    async_socket.async_connect(ep, boost::bind(&async_tcp_client::connect_handler, this, boost::asio::placeholders::error));
    ctx.run();
}

