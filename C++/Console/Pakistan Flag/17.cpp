#include <iostream>
#include <windows.h>  // For Sleep function
using namespace std;

// ANSI escape codes for colors
#define GREEN "\033[42m  \033[0m"     // Green background
#define WHITE "\033[47m  \033[0m"     // White background
#define RESET "\033[0m"               // Reset color
#define WHITE_TEXT "\033[97m"         // White text color

// Function to print a row of the flag
void printRow(const string& pattern) {
    for (char c : pattern) {
        if (c == 'G') {
            cout << GREEN;
        }
        else {
            cout << WHITE;
        }
    }
    cout << RESET << endl;
    Sleep(200);  // Pause for 200 milliseconds
}

// Function to print a message with white text
void printMessage(const string& message) {
    cout << WHITE_TEXT << message << RESET << endl;  // White text
    Sleep(500);  // Pause for 500 milliseconds
}

int main() {
    const int height = 7;  // Total height of the flag

    // Print celebratory message
    printMessage("**********************************");
    printMessage("Happy Independence Day, Pakistan!");
    printMessage("14th August 2024");
    printMessage("**********************************");

    // Top stripes
    for (int i = 0; i < height / 2 - 1; ++i) {
        printRow("WWWWWWWWGGGGGGGGGGGGGGGGGGG");
    }

    // Middle part with crescent and star
    printRow("WWWWWWWWGGGGGGGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGGGGGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGGGGGWGGGGWGGGGGG");
    printRow("WWWWWWWWGGGGGWWWGGGWWWGGGGG");
    printRow("WWWWWWWWGGGGWWWGGGGGWGGGGGG");
    printRow("WWWWWWWWGGGGWWGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGWWWGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGWWWGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGWWWGGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGWWWWGGGGGGGGGGGG");
    printRow("WWWWWWWWGGGGWWWWGGGWWGGGGGG");
    printRow("WWWWWWWWGGGGWWWWWWWWGGGGGGG");
    printRow("WWWWWWWWGGGGGGWWWWGGGGGGGGG");
    printRow("WWWWWWWWGGGGGGGGGGGGGGGGGGG");

    // Bottom stripes
    for (int i = 0; i < height / 2 - 1; ++i) {
        printRow("WWWWWWWWGGGGGGGGGGGGGGGGGGG");
    }

    // Print closing message
    printMessage("**********************************");
    printMessage("Pakistan Zindabad!");
    printMessage("**********************************");

    return 0;
}
