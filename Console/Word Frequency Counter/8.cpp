/*
#include <sstream>
#include <iostream>
int main() {
	std::stringstream ss;
	ss << "The number is " << 42;
	std::string result = ss.str(); // result will be "The number is 42"
	std::cout << result;
}
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_WORDS = 100; // Define a maximum number of different words

void countWordFrequency(const string& input) {
    std::string words[MAX_WORDS]; // Array to store unique words
    int wordCounts[MAX_WORDS] = { 0 }; // Array to store word counts
    int uniqueWordCount = 0; // Counter for unique words

    istringstream stream(input); // Stream to read words from the input string
    string word; // Variable to hold each word

    // Read words from the input string and count their frequencies
    while (stream >> word) {
        // Check if the word is already in the words array
        bool wordFound = false; // Flag to check if the word is already in the array
        for (int i = 0; i < uniqueWordCount; ++i) {
            if (words[i] == word) {
                wordCounts[i]++; // Increment the count for the existing word
                wordFound = true;
                break;
            }
        }

        // If the word is not found in the array, add it as a new unique word
        if (!wordFound) {
            words[uniqueWordCount] = word;
            wordCounts[uniqueWordCount] = 1;
            uniqueWordCount++;
        }
    }

    // Print the word frequencies
    for (int i = 0; i < uniqueWordCount; ++i) {
        cout << words[i] << " -> " << wordCounts[i] << std::endl;
    }
}

int main() {
    
    // Input strings
    string input1 = "program is program where program is where";
    string input2 = "hello world world hello";

    // Process the first input
    cout << "Input: " << input1 << endl;
    cout << "Output:" << endl;
    countWordFrequency(input1);

    cout << endl;

    // Process the second input
    cout << "Input: " << input2 << endl;
    cout << "Output:" << endl;
    countWordFrequency(input2);

    return 0;
}
