#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_WORDS = 100; // Define a maximum number of different words

void reverseWords(const string& input) {
    string words[MAX_WORDS]; // Fixed-size array to store words
    int wordCount = 0; // Counter for the number of words

    stringstream stream(input); // Create a stream to read the input string
    string word;

    // Read each word from the input string and store in the array
    while (stream >> word && wordCount < MAX_WORDS) {
        words[wordCount] = word;
        wordCount++;
    }

    // Print words in reverse order
    for (int i = wordCount - 1; i >= 0; --i) {
        cout << words[i];
        if (i > 0) {
            cout << " "; // Add space between words
        }
    }
    cout << endl;
}

int main() {
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input); // Read the entire input line

    cout << "Original sentence: " << input << endl;

    cout << "Reversed words: ";
    reverseWords(input);

    return 0;
}
