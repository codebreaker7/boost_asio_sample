#ifndef SYNC_TCP_SERVER_H
#define SYNC_TCP_SERVER_H

#include <boost/asio.hpp>
#include "basic_server.h"

using namespace boost::asio;
using namespace boost::asio::ip;

class sync_tcp_server : public basic_server
{
public:
    sync_tcp_server(io_context& context);
    virtual void run_server();
private:
    tcp::acceptor * acceptor;
    tcp::socket * sync_serv_socket;
};

#endif // SYNC_TCP_SERVER_H
