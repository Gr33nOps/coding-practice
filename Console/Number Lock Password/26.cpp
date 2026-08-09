#include <iostream>
#include <conio.h>
#include <windows.h> // For console color manipulation

using namespace std;

// Function to set text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to reset text color
void resetColor() {
    setColor(7); // Default color (light gray on black)
}

// Function to display and set the password
void setPassword(int password[], const int passwordLength) {
    int index = 0; // Current position in the password array
    bool settingPassword = true;

    setColor(14); // Yellow color for instructions
    cout << "Use arrow keys (UP & DOWN to change numbers, LEFT & RIGHT to move positions).\n";
    cout << "Press ENTER to set the password.\n\n";
    resetColor();

    while (settingPassword) {
        // Display the current password setting
        cout << "\r";
        setColor(10); // Green color for the password prompt
        cout << "Password: ";
        resetColor();

        for (int i = 0; i < passwordLength; ++i) {
            if (i == index) {
                setColor(11); // Cyan color for the current position
                cout << "[" << password[i] << "] "; // Highlight current position
                resetColor(); // Reset to default color
            }
            else {
                cout << password[i] << " ";
            }
        }

        if (_kbhit()) {
            int ch = _getch();

            if (ch == 224) { // Arrow keys start with 224
                ch = _getch(); // Get the specific arrow key code

                if (ch == 72) { // Up arrow key
                    password[index] = (password[index] == 9) ? 0 : password[index] + 1;
                }
                else if (ch == 80) { // Down arrow key
                    password[index] = (password[index] == 0) ? 9 : password[index] - 1;
                }
                else if (ch == 75) { // Left arrow key
                    index = (index == 0) ? passwordLength - 1 : index - 1;
                }
                else if (ch == 77) { // Right arrow key
                    index = (index == passwordLength - 1) ? 0 : index + 1;
                }
            }
            else if (ch == 13) { // Enter key
                settingPassword = false; // Exit the loop when Enter is pressed
            }
        }
    }
}

// Function to display and check the password
bool checkPassword(const int correctPassword[], const int passwordLength) {
    const int maxPasswordLength = 4; // Define a maximum size
    int attemptPassword[maxPasswordLength] = { 0 }; // Password attempt
    int index = 0; // Current position in the password array
    bool checkingPassword = true;

    setColor(14); // Yellow color for instructions
    cout << "\nUse arrow keys (↑ ↓ to change numbers, ← → to move positions) to unlock.\n";
    cout << "Press Enter when done.\n\n";
    resetColor();

    while (checkingPassword) {
        // Display current attempt password
        cout << "\r";
        setColor(10); // Green color for the attempt prompt
        cout << "Attempt: ";
        resetColor();

        for (int i = 0; i < maxPasswordLength; ++i) {
            if (i == index) {
                setColor(11); // Cyan color for the current position
                cout << "[" << attemptPassword[i] << "] "; // Highlight current position
                resetColor(); // Reset to default color
            }
            else {
                cout << attemptPassword[i] << " ";
            }
        }

        if (_kbhit()) {
            int ch = _getch();

            if (ch == 224) { // Arrow keys start with 224
                ch = _getch(); // Get the specific arrow key code

                if (ch == 72) { // Up arrow key
                    attemptPassword[index] = (attemptPassword[index] == 9) ? 0 : attemptPassword[index] + 1;
                }
                else if (ch == 80) { // Down arrow key
                    attemptPassword[index] = (attemptPassword[index] == 0) ? 9 : attemptPassword[index] - 1;
                }
                else if (ch == 75) { // Left arrow key
                    index = (index == 0) ? maxPasswordLength - 1 : index - 1;
                }
                else if (ch == 77) { // Right arrow key
                    index = (index == maxPasswordLength - 1) ? 0 : index + 1;
                }
            }
            else if (ch == 13) { // Enter key
                checkingPassword = false; // Exit the loop when Enter is pressed
            }
        }
    }

    // Check if the entered password matches the correct password
    bool isUnlocked = true;
    for (int i = 0; i < maxPasswordLength; ++i) {
        if (attemptPassword[i] != correctPassword[i]) {
            isUnlocked = false;
            break;
        }
    }

    return isUnlocked;
}

int main() {
    const int passwordLength = 4;
    int password[passwordLength] = { 0 }; // Password to be set

    // Set the password
    setColor(14); // Yellow color for welcome message
    cout << "Welcome! Let's set your 4-digit password.\n";
    resetColor();
    setPassword(password, passwordLength);

    setColor(10); // Green color for success message
    cout << "\nPassword set successfully!\n";
    resetColor();

    // Lock activation message
    setColor(12); // Red color for activation message
    cout << "The lock is now activated.\n";
    cout << "Press 'F' to unlock.\n";
    resetColor();

    // Wait for user to press 'F'
    bool waitingForUnlock = true;
    while (waitingForUnlock) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'f' || ch == 'F') { // If 'F' is pressed
                waitingForUnlock = false;
            }
        }
    }

    // Check the password
    bool isUnlocked = checkPassword(password, passwordLength);

    // Display result
    if (isUnlocked) {
        setColor(10); // Green color for success message
        cout << "\n\nUnlocked successfully!\n";
    }
    else {
        setColor(12); // Red color for failure message
        cout << "\n\nIncorrect password! The lock remains.\n";
    }
    resetColor();

    return 0;
}