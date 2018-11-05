#include <iostream>
#include <map>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "basic_client.h"
#include "sync_tcp_client.h"
#include "async_tcp_client.h"
#include "sync_tcp_server.h"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

int main()
{
    try {
        io_context client_context;
        io_context server_context;
        //basic_client * client = new sync_tcp_client(client_context);
        basic_client * client = new async_tcp_client(client_context);
        basic_server * server = new sync_tcp_server(server_context);

        //server->run_server();
        boost::thread t(boost::bind(&basic_server::run_server, server));
        client->do_work();
        t.join();
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

