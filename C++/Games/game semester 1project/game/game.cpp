#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int ROWS = 25;
const int COLS = 80;
const int ROBOT_HEIGHT = 3;
const int ROBOT_WIDTH = 5;
const int SPEED[] = { 300, 200, 100 }; // Speeds for difficulty levels 1, 2, 3

// Function to clear the console screen
void clearScreen() {
    system("cls");
}
// Function to draw the game grid with a border
void drawGrid(char grid[][COLS], int robotRow, int robotCol) {
    // Draw top border
    cout << "+";
    for (int j = 0; j < COLS; ++j) {
        cout << "-";
    }
    cout << "+" << endl;

    // Draw grid with border
    for (int i = 0; i < ROWS; ++i) {
        cout << "|"; // Left border
        for (int j = 0; j < COLS; ++j) {
            if ((i >= robotRow && i < robotRow + ROBOT_HEIGHT) && (j >= robotCol && j < robotCol + ROBOT_WIDTH)) {
                if (j == robotCol) {
                    cout << "\\"; // Draw the left side of the robot
                }
                else if (j == robotCol + ROBOT_WIDTH - 1) {
                    cout << "/";
                }
                else {
                    cout << "O"; // Draw the body of the robot
                }
            }
            else {
                if (grid[i][j] == '.') {
                    cout << " ";
                }
                else {
                    cout << grid[i][j];
                }
            }
        }
        cout << "|"; // Right border
        cout << endl;
    }

    // Draw bottom border
    cout << "+";
    for (int j = 0; j < COLS; ++j) {
        cout << "-";
    }
    cout << "+" << endl;
}

// Function to update robot position based on user input
void updateRobotPosition(int& robotRow, int& robotCol, char userInput) {
    switch (userInput) {
    case 'a':
    case 'A':
        if (robotCol > 0) robotCol--;
        break;
    case 'd':
    case 'D':
        if (robotCol + ROBOT_WIDTH < COLS) robotCol++;
        break;
    }
}

// Function to generate a random number
int generateRandomNumber() {
    return rand() % 10;
}

void updateFallingNumbers(char grid[][COLS], int robotRow, int& numFalling, int maxFalling) {
    int count = 0; // Count of currently falling numbers

    // Shift existing numbers down and clear top row
    for (int i = ROWS - 1; i > 0; --i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i - 1][j] >= '0' && grid[i - 1][j] <= '9') {
                if (i < ROWS - 1) {
                    grid[i][j] = grid[i - 1][j]; // Move the falling number down
                    grid[i - 1][j] = '.'; // Clear the cell above
                }
                else {
                    grid[i - 1][j] = '.'; // Clear the top row
                }
                count++;
            }
        }
    }

    // Generate new falling numbers
    while (count < maxFalling) {
        int j = rand() % COLS;
        if (grid[0][j] == '.') {
            grid[0][j] = '0' + generateRandomNumber();
            count++;
        }
    }

    numFalling = count;

    // Check for collision with the bottom border and clear the number
    for (int j = 0; j < COLS; ++j) {
        if (grid[ROWS - 1][j] >= '0' && grid[ROWS - 1][j] <= '9') {
            grid[ROWS - 1][j] = '.'; // Clear the cell if it touches the bottom border
            numFalling--;
        }
    }

    // Check for collision with the robot and clear the number
    for (int j = 0; j < COLS; ++j) {
        if (grid[robotRow][j] >= '0' && grid[robotRow][j] <= '9') {
            grid[robotRow][j] = '.'; // Clear the cell if it contains a falling number
            numFalling--;
        }
    }
}


int main() {
    srand(time(0));

    char grid[ROWS][COLS];
    int robotRow = ROWS - ROBOT_HEIGHT; // Starting row of the robot
    int robotCol = COLS / 2 - ROBOT_WIDTH / 2; // Starting column of the robot
    int score = 0;
    int numFalling = 0;
    int maxFalling = 3; // Maximum number of falling numbers

    // Initialize the grid
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = '.';
        }
    }

    char userInput;
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    cout << "Select difficulty (1 - Easy, 2 - Medium, 3 - Hard): ";
    int difficulty;
    cin >> difficulty;

    cout << "Press any key to start...";
    _getch(); // Wait for user input to start the game

    time_t startTime = time(0);
    time_t endTime = startTime + 180; // 3 minutes game duration

    while (time(0) < endTime) {
        clearScreen();
        updateFallingNumbers(grid, robotRow, numFalling, maxFalling);
        drawGrid(grid, robotRow, robotCol);

        if (_kbhit()) {
            userInput = _getch();
            if (userInput == 'p' || userInput == 'P') {
                cout << "Game Paused. Press any key to continue...";
                _getch();
            }
            else if (userInput == 27) { // 'Esc' key
                break;
            }
            else {
                updateRobotPosition(robotRow, robotCol, userInput);
            }
        }

        // Check for collisions with falling numbers
        for (int j = robotCol; j < robotCol + ROBOT_WIDTH; ++j) {
            if (robotRow >= 0 && robotRow < ROWS && grid[robotRow][j] >= '0' && grid[robotRow][j] <= '9') {
                score += grid[robotRow][j] - '0'; // Increment score
                grid[robotRow][j] = '.'; // Clear the collected number
            }
        }

        // Sleep for speed based on difficulty
        Sleep(SPEED[difficulty - 1]);
    }

    cout << "Game over! Your final score is: " << score << endl;

    return 0;
}
