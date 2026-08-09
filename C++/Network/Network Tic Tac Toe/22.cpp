#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

// Utility functions to set and reset color
void setColor(int color) {
    cout << "\033[" << color << "m";
}

void resetColor() {
    cout << "\033[0m";
}

// Tic-Tac-Toe game class
class TicTacToe {
private:
    char board[3][3];
    int current_player;  // 1 for Player 1, 2 for Player 2

public:
    TicTacToe() {
        char temp_board[3][3] = { {'1', '2', '3'},
                                  {'4', '5', '6'},
                                  {'7', '8', '9'} };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = temp_board[i][j];
            }
        }
        srand(static_cast<unsigned>(time(0)));
        current_player = rand() % 2 + 1;  // Randomly select the first player
    }

    void drawBoard() const {
        setColor(36); // Cyan color for headers
        cout << "\n=================================\n";
        setColor(35); // Magenta color for title
        cout << "         Tic-Tac-Toe Game         \n";
        setColor(36); // Cyan color for headers
        cout << "=================================\n\n";

        setColor(33); // Yellow color for players
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";

        setColor(37); // White color for the board
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "__|_|__\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "__|_|__\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "     |     |     \n\n";
    }

    bool placeMarker(int slot, char marker) {
        int row_col[9][2] = {
            {0, 0}, {0, 1}, {0, 2},
            {1, 0}, {1, 1}, {1, 2},
            {2, 0}, {2, 1}, {2, 2}
        };

        int row = row_col[slot - 1][0];
        int col = row_col[slot - 1][1];

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = marker;
            return true;
        }
        return false;
    }

    int checkWinner() const {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return current_player;
        }

        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return current_player;
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return current_player;

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return current_player;

        return 0;
    }

    void swapPlayer() {
        current_player = (current_player == 1) ? 2 : 1;
    }

    int getCurrentPlayer() const {
        return current_player;
    }

    char getMarkerForPlayer(int player) const {
        return (player == 1) ? 'X' : 'O';
    }

    string getBoardAsString() const {
        string board_string;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board_string += board[i][j];
                if (j < 2) board_string += '|';
            }
            if (i < 2) board_string += "\n-----\n";
        }
        return board_string;
    }

    bool isDraw() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }
};

// Server functionality
void runServer() {
    io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
    cout << "Server is running. Waiting for a connection...\n";

    tcp::socket socket(io_context);
    acceptor.accept(socket);

    TicTacToe game;

    while (true) {
        game.drawBoard();
        string message = game.getBoardAsString() + "\n";
        boost::asio::write(socket, boost::asio::buffer(message));

        int current_player = game.getCurrentPlayer();
        char marker = game.getMarkerForPlayer(current_player);

        boost::asio::streambuf receive_buffer;
        boost::asio::read_until(socket, receive_buffer, "\n");
        istream input_stream(&receive_buffer);
        int move;
        input_stream >> move;

        if (game.placeMarker(move, marker)) {
            int winner = game.checkWinner();
            if (winner != 0) {
                game.drawBoard();
                message = "Player " + to_string(winner) + " wins!\n";
                boost::asio::write(socket, boost::asio::buffer(message));
                break;
            }
            else if (game.isDraw()) {
                game.drawBoard();
                message = "It's a draw!\n";
                boost::asio::write(socket, boost::asio::buffer(message));
                break;
            }

            game.swapPlayer();
        }
    }
}

// Client functionality
void runClient() {
    io_context io_context;
    tcp::socket socket(io_context);
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 12345));

    TicTacToe game;

    while (true) {
        boost::asio::streambuf receive_buffer;
        boost::asio::read_until(socket, receive_buffer, "\n");
        istream input_stream(&receive_buffer);
        string server_message;
        getline(input_stream, server_message);
        cout << server_message << endl;

        game.drawBoard();

        int current_player = game.getCurrentPlayer();
        char marker = game.getMarkerForPlayer(current_player);

        int move;
        cout << "Player " << current_player << "'s turn (" << marker << "). Enter your move (1-9): ";
        cin >> move;

        if (game.placeMarker(move, marker)) {
            boost::asio::write(socket, boost::asio::buffer(to_string(move) + "\n"));
            game.swapPlayer();
        }

        // Check if the server sent a win or draw message
        if (server_message.find("wins") != string::npos || server_message.find("draw") != string::npos) {
            break;
        }
    }
}

int main() {
    setColor(33); // Yellow color for instructions
    cout << "Welcome to Tic-Tac-Toe!\n";
    resetColor();
    cout << "Choose mode: 1) Server 2) Client\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        runServer();
    }
    else if (choice == 2) {
        runClient();
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}