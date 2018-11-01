#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

int main()
{
    try {
        io_context context;
        boost::system::error_code ec;
        tcp::socket sync_socket(context);
        boost::array<char, 1024> readbuf;

        tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 33333);
        sync_socket.connect(ep, ec);
        if (ec) {
            cerr << "Problem with connection" << endl;
            return 1;
        }
        // write start message
        sync_socket.write_some(buffer("HELLO"), ec);
        if (ec) {
            cerr << "Cannot write data!" << endl;
            return 1;
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
    catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

