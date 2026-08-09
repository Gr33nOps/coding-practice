#include <iostream>
#include <string>
#include <iomanip>  // For setting decimal precision

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);  // Convert the character to lowercase for easy comparison
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string input;
    int vowelCount = 0, consonantCount = 0, digitCount = 0, spaceCount = 0;

    cout << "Enter a string: ";
    getline(cin, input);

    for (char ch : input) {
        if (isalpha(ch)) {  // Check if the character is an alphabet letter
            if (isVowel(ch)) {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (isdigit(ch)) {  // Check if the character is a digit
            digitCount++;
        }
        else if (isspace(ch)) {  // Check if the character is a space
            spaceCount++;
        }
    }

    int totalChars = input.length();

    cout << "\nAnalysis of the input string:\n";
    cout << "Number of vowels: " << vowelCount << " (" << fixed << setprecision(2)
        << (100.0 * vowelCount / totalChars) << "%)" << endl;
    cout << "Number of consonants: " << consonantCount << " (" << fixed << setprecision(2)
        << (100.0 * consonantCount / totalChars) << "%)" << endl;
    cout << "Number of digits: " << digitCount << " (" << fixed << setprecision(2)
        << (100.0 * digitCount / totalChars) << "%)" << endl;
    cout << "Number of spaces: " << spaceCount << " (" << fixed << setprecision(2)
        << (100.0 * spaceCount / totalChars) << "%)" << endl;

    return 0;
}
