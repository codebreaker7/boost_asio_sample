#ifndef BASIC_CLIENT_H
#define BASIC_CLIENT_H

#include <boost/asio.hpp>

using namespace boost::asio;

class basic_client
{
public:
    basic_client(io_context &context);
    virtual void do_work() = 0;
protected:
    io_context& ctx;
};

#endif // BASIC_CLIENT_H
