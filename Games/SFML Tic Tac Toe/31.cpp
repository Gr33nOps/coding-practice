
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GAME {
private:
    char board[3][3];

public:
    GAME() {
        char tempBoard[3][3] = { {'1','2','3'},
                                 {'4','5','6'},
                                 {'7','8','9'} };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = tempBoard[i][j];
            }
        }
    }

    bool placeMarker(int row, int col, char marker) {
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = marker;
            return true;
        }
        return false;
    }

    void drawBoard(RenderWindow& window) {
        const int size = 100;
        int padding = 5;

        RectangleShape blocks[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                blocks[i][j].setSize(Vector2f(size, size));

                int x = j * size + j * padding;
                int y = i * size + i * padding;

                blocks[i][j].setPosition(x, y);

                if (board[i][j] == 'X') {
                    blocks[i][j].setFillColor(Color::Red);
                }
                else if (board[i][j] == 'O') {
                    blocks[i][j].setFillColor(Color::Green);
                }
                else {
                    blocks[i][j].setFillColor(Color::White);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                window.draw(blocks[i][j]);
            }
        }
    }

    int checkWinner() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                return board[i][0] == 'X' ? 1 : (board[i][0] == 'O' ? 2 : 0);
            }
        }
        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[2][0] == board[1][1] && board[1][1] == board[0][2])) {
            return board[1][1] == 'X' ? 1 : (board[1][1] == 'O' ? 2 : 0);
        }
        return 0; // No winner
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }

    void resetBoard() {
        char tempBoard[3][3] = { {'1','2','3'},
                                 {'4','5','6'},
                                 {'7','8','9'} };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = tempBoard[i][j];
            }
        }
    }
};

int main() {
    RenderWindow window(VideoMode(310, 310), "Tic Tac Toe");
    GAME game;

    int currentPlayer = 1;
    char currentMarker = 'X';
    string message;
    Font font;
    Text text;

    if (!font.loadFromFile("Square.ttf")) {
        cerr << "Error loading file";
    }
    text.setFont(font);
    text.setFillColor(Color::White);

    bool gameOver = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed && !gameOver) {
                int row = event.mouseButton.y / 110;
                int col = event.mouseButton.x / 110;

                if (game.placeMarker(row, col, currentMarker)) {
                    int winner = game.checkWinner();
                    if (winner) {
                        message = (winner == 1) ? "Player 1 wins!" : "Player 2 wins!";
                        gameOver = true;
                    }
                    else if (game.isBoardFull()) {
                        message = "Tie!";
                        gameOver = true;
                    }
                    else {
                        currentPlayer = (currentPlayer == 1) ? 2 : 1;
                        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
                    }
                }
            }

            if (gameOver && event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                game.resetBoard();
                message.clear();
                currentPlayer = 1;
                currentMarker = 'X';
                gameOver = false;
            }
        }

        window.clear(Color::Black);
        game.drawBoard(window);

        if (!message.empty()) {
            window.clear(Color::Black);
            text.setString(message);
            text.setCharacterSize(40);

            FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
            text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 10);

            window.draw(text);

            // Draw play again message
            Text playAgainText;
            playAgainText.setFont(font);
            playAgainText.setFillColor(Color::White);
            playAgainText.setString("Press Spacebar to play again");
            playAgainText.setCharacterSize(20);
            FloatRect playAgainRect = playAgainText.getLocalBounds();
            playAgainText.setOrigin(playAgainRect.width / 2.0f, playAgainRect.height / 2.0f);
            playAgainText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 30);

            window.draw(playAgainText);
        }

        window.display();
    }

    return 0;
}

