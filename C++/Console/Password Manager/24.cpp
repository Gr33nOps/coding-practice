#include <iostream>
#include <string>
#include <conio.h> // For getch()

using namespace std;

const int MAX_PASSWORDS = 5; // Maximum number of passwords that can be stored

struct PasswordEntry {
    string website;
    string username;
    string password;
};

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        cout << "Password storage is full. Cannot add more passwords.\n";
        return;
    }

    PasswordEntry entry;

    cout << "Enter website: ";
    cin >> entry.website;

    cout << "Enter username: ";
    cin >> entry.username;

    cout << "Enter password: ";
    char ch;
    string passInput;
    while ((ch = _getch()) != '\r') { // Capture password without displaying it
        passInput += ch;
        cout << '*'; // Display asterisks instead of characters
    }
    entry.password = passInput;
    cout << endl;

    passwordList[passwordCount] = entry;
    passwordCount++;

    cout << "Password added successfully.\n";
}

void viewPasswords() {
    if (passwordCount == 0) {
        cout << "No passwords stored.\n";
        return;
    }

    cout << "Stored passwords:\n";
    for (int i = 0; i < passwordCount; i++) {
        cout << "Website: " << passwordList[i].website << endl;
        cout << "Username: " << passwordList[i].username << endl;
        cout << "Password: " << passwordList[i].password << endl;
        cout << "---------------------------\n";
    }
}

void searchPassword() {
    if (passwordCount == 0) {
        cout << "No passwords stored.\n";
        return;
    }

    string searchSite;
    cout << "Enter website to search: ";
    cin >> searchSite;

    for (int i = 0; i < passwordCount; i++) {
        if (passwordList[i].website == searchSite) {
            cout << "Website: " << passwordList[i].website << endl;
            cout << "Username: " << passwordList[i].username << endl;
            cout << "Password: " << passwordList[i].password << endl;
            return;
        }
    }

    cout << "No password found for the given website.\n";
}

int main() {
    int choice;
    do {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Search Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            searchPassword();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
