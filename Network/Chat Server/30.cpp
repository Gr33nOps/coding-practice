#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

// Function to read data from the socket until a newline character is encountered
string getData(tcp::socket& socket)
{
    boost::asio::streambuf buf;
    boost::system::error_code error;
    boost::asio::read_until(socket, buf, "\n", error);

    if (error && error != boost::asio::error::eof) {
        throw boost::system::system_error(error);
    }

    string data = buffer_cast<const char*>(buf.data());
    return data;
}

// Function to send data through the socket
void sendData(tcp::socket& socket, const string& message)
{
    boost::asio::write(socket, buffer(message + "\n"));
}

int main(int argc, char* argv[])
{
    io_service io_service;

    // Listening for any new incoming connection at port 9999 with IPv4 protocol
    tcp::acceptor acceptor_server(io_service, tcp::endpoint(tcp::v4(), 9999));

    // Creating socket object
    tcp::socket server_socket(io_service);

    // Waiting for connection
    acceptor_server.accept(server_socket);

    // Reading username
    string u_name = getData(server_socket);
    // Removing "\n" from the username
    u_name.pop_back();

    // Replying with default message to initiate chat
    string response, reply;
    reply = "Hello " + u_name + "!";
    cout << "Server: " << reply << endl;
    sendData(server_socket, reply);

    while (true) {
        // Fetching response
        response = getData(server_socket);

        // Popping last character "\n"
        response.pop_back();

        // Validating if the connection has to be closed
        if (response == "exit") {
            cout << u_name << " left!" << endl;
            break;
        }
        cout << u_name << ": " << response << endl;

        // Reading new message from input stream
        cout << "Server: ";
        getline(cin, reply);
        sendData(server_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}
