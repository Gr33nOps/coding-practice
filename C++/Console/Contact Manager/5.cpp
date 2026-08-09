#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

struct Contact {
    string name;
    string phone;
    string email;
};

void addContact(Contact contacts[], int& numContacts) {
    if (numContacts >= MAX_CONTACTS) {
        cout << "Contact list is full!\n";
        return;
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, contacts[numContacts].name);
    cout << "Enter phone number: ";
    getline(cin, contacts[numContacts].phone);
    cout << "Enter email: ";
    getline(cin, contacts[numContacts].email);

    numContacts++;
    cout << "Contact added successfully!\n";
}

void displayContacts(const Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        cout << "No contacts available.\n";
        return;
    }

    cout << "Contacts List:\n";
    for (int i = 0; i < numContacts; i++) {
        cout << "-----------------------\n";
        cout << "Name: " << contacts[i].name << "\n";
        cout << "Phone: " << contacts[i].phone << "\n";
        cout << "Email: " << contacts[i].email << "\n";
    }
}

void searchContact(const Contact contacts[], int numContacts) {
    string name;
    cout << "Enter name to search: ";
    cin.ignore(); 
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == name) {
            cout << "\nContact found:\n";
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Phone: " << contacts[i].phone << "\n";
            cout << "Email: " << contacts[i].email << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found.\n";
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        cout << "Contact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts, numContacts);
            break;
        case 2:
            displayContacts(contacts, numContacts);
            break;
        case 3:
            searchContact(contacts, numContacts);
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
