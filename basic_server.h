#ifndef BASIC_SERVER_H
#define BASIC_SERVER_H

#include <boost/asio.hpp>

using namespace boost::asio;

class basic_server
{
public:
    basic_server(io_context&  context);
    virtual void run_server() = 0;
private:
    io_context& ctx;
};

#endif // BASIC_SERVER_H
