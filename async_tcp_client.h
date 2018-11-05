#ifndef ASYNC_TCP_CLIENT_H
#define ASYNC_TCP_CLIENT_H

#include <basic_client.h>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

class async_tcp_client : public basic_client
{
public:
    async_tcp_client(io_context& context);
    void connect_handler(const boost::system::error_code& e);
    void write_handler(const boost::system::error_code& e, size_t written);
    void read_handler(const boost::system::error_code& e, size_t transferred);
    virtual void do_work();
private:
    tcp::socket async_socket;
    char cbuf[1024];
};

#endif // ASYNC_TCP_CLIENT_H
