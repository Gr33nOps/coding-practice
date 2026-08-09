#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    const int passwordLength = 4;
    int password[passwordLength] = { 0, 0, 0, 0 }; // Password to be set
    int index = 0; // Current position in the password array

    cout << "Use arrow keys (UP & DOWN to change numbers, LEFT & RIGHT to move positions).\n";
    cout << "Press ENTER to set the password.\n\n";

    bool settingPassword = true;
    while (settingPassword) {
        // Display the current password setting
        cout << "\rPassword: ";
        for (int i = 0; i < passwordLength; ++i) {
            if (i == index)
                cout << "[" << password[i] << "] "; // Highlight current position
            else
                cout << password[i] << " ";
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

    cout << "\nPassword set successfully!\n";

    return 0;
}