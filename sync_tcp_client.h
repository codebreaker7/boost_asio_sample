#ifndef SYNC_TCP_CLIENT_H
#define SYNC_TCP_CLIENT_H

#include <boost/asio.hpp>
#include "basic_client.h"

using namespace boost::asio;
using namespace boost::asio::ip;

class sync_tcp_client : public basic_client
{
public:
    sync_tcp_client(io_context& context);
    virtual void do_work();
private:
    tcp::socket sync_socket;
};

#endif // SYNC_TCP_CLIENT_H
