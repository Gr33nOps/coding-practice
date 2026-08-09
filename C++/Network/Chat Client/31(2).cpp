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
    // Socket creation
    ip::tcp::socket client_socket(io_service);

    client_socket.connect(tcp::endpoint(address::from_string("127.0.0.1"), 9999));

    // Getting username from user
    string u_name = "Client", reply, response;

    // Sending username to another end to initiate the conversation
    sendData(client_socket, u_name);

    // Infinite loop for chit-chat
    while (true) {
        // Fetching response
        response = getData(client_socket);

        // Popping last character "\n"
        response.pop_back();

        // Validating if the connection has to be closed
        if (response == "exit") {
            cout << "Connection terminated" << endl;
            break;
        }
        cout << "Server: " << response << endl;

        // Reading new message from input stream
        cout << u_name << ": ";
        getline(cin, reply);
        sendData(client_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}