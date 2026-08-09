#include <iostream>
#include <conio.h> // For _getch(), _kbhit()
#include <thread>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <windows.h> // For setting text color

using namespace std;

// Function to set text color
void setTextColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

// Function to clear the screen
void clearScreen() {
    system("CLS"); // Clears the console screen
}

// Function to generate a random lowercase character
char getRandomCharacter() {
    return 'a' + rand() % 26; // Lowercase letters only
}

// Function to display the border
void displayBorder() {
    setTextColor(15); // White text
    cout << "--------------------------------------------------------" << endl;
}

// Function to display the score
void displayScore(int score) {
    setTextColor(15); // White text for the score
    cout << "Score: " << score << endl;
}

// Function to display the target character
void displayTargetCharacter(char targetChar) {
    setTextColor(14); // Yellow text for the target character
    cout << "Catch this character: " << targetChar << endl;
    setTextColor(15); // Reset text color to white
}

// Function to display the start menu
void displayStartMenu() {
    clearScreen();
    setTextColor(15); // White text
    cout << "Welcome to the Enhanced 'Catch the Character' Game!" << endl;
    cout << "Press 's' to start the game." << endl;
    cout << "Press 'q' to quit the game." << endl;
    setTextColor(15); // Reset text color to white
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int score = 0;
    char targetChar;
    char userInput;

    // Display the start menu
    displayStartMenu();

    while (true) {
        userInput = _getch(); // Wait for user input

        if (userInput == 's') {
            clearScreen();
            setTextColor(15); // White text
            cout << "Game starting!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break; // Exit the start menu loop
        }
        else if (userInput == 'q') {
            clearScreen();
            setTextColor(15); // White text
            cout << "You chose to quit. Exiting now..." << endl;
            return 0;
        }
        else {
            displayStartMenu(); // Redisplay the start menu if the input is invalid
        }
    }

    auto gameStart = chrono::steady_clock::now(); // Record the start time

    while (chrono::steady_clock::now() - gameStart < chrono::seconds(30)) { // Run for 30 seconds
        targetChar = getRandomCharacter(); // Generate a random character

        // Display the target character and score
        clearScreen(); // Clear the screen before displaying new content
        displayBorder();
        displayScore(score);
        displayTargetCharacter(targetChar);
        displayBorder();

        auto start = chrono::steady_clock::now();
        bool keyPressed = false;

        while (chrono::steady_clock::now() - start < chrono::seconds(2)) {
            if (_kbhit()) {
                userInput = _getch(); // Capture the user's input
                if (userInput == targetChar) {
                    score++;
                    keyPressed = true;
                    break;
                }
                else if (userInput != 'q') { // Ignore 'q' and other keys
                    keyPressed = true;
                }
            }
            this_thread::sleep_for(chrono::milliseconds(100)); // Small delay to reduce CPU usage
        }

        if (!keyPressed) {
            score--; // Deduct points if time is up and no key was pressed
        }
    }

    // Game over message
    clearScreen();
    setTextColor(15); // White text
    displayBorder();
    cout << "Time's up!" << endl;
    displayBorder();
    setTextColor(10); // Green text for the final score
    cout << "Your final score is: " << score << endl;
    displayBorder();

    return 0;
}
