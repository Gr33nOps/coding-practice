#include <iostream>
#include <string>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    string surah;      // Name of Surah
    int ayah;          // Ayah number
    string text;       // Text of the verse
    Node* next;        // Pointer to the next node
    Node* prev;        // Pointer to the previous node

    // Constructor to initialize a node
    Node(string Name, int Number, string Versetext)
    {
        surah = Name;
        ayah = Number;
        text = Versetext;
        next = nullptr;
        prev = nullptr;
    }
};

// Global pointers for the list
Node* head = NULL;
Node* tail = NULL;

// Insert a verse at the end of the list
void insertVerse(string surah, int ayah, string text) {
    Node* newNode = new Node(surah, ayah, text);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Delete a verse at a specific position
void deleteVerse(int position) {
    if (head == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    Node* temp = head;
    int currentPos = 1;

    while (temp != NULL && currentPos < position) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) head->prev = NULL;
    }
    else if (temp == tail) {
        tail = temp->prev;
        if (tail != NULL) tail->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted verse at position " << position << endl;
}

// Search for a verse by Surah and Ayah
void searchVerse(string surah, int ayah) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->surah == surah && temp->ayah == ayah) {
            cout << "Found: " << temp->text << " (Surah: " << surah << ", Ayah: " << ayah << ")" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Verse not found!" << endl;
}

// Display all verses
void displayVerses() {
    if (head == NULL) {
        cout << "No verses to display!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "Surah: " << temp->surah << ", Ayah: " << temp->ayah << ", Verse: " << temp->text << endl;
        temp = temp->next;
    }
}

int main() {
    cout << "Bismillah ar-Rahman ar-Rahim\n";
    cout << "----------------------------\n";
    // Insert verses
    insertVerse("Al-Fatiha", 1, "In the name of Allah, the Most Gracious, the Most Merciful.");
    insertVerse("Al-Baqarah", 255, "Allah! There is no deity except Him, the Ever-Living, the Sustainer of existence.");

    // Display verses
    cout << "All verses:" << endl;
    displayVerses();

    // Search for a verse
    searchVerse("Al-Fatiha", 1);

    // Delete a verse
    deleteVerse(1);

    // Display verses after deletion
    cout << "\nVerses after deletion:" << endl;
    displayVerses();

    return 0;
}
