#include <iostream>
#include <string>

using namespace std;

void demonstrateAdditionalStringOperations() {
    // Initializing strings
    string str1 = "Hello, World!";
    string str2 = "C++ String Library";

    // 1. Finding Substrings
    size_t pos = str1.find("World");
    cout << "1. Finding Substrings:" << endl;
    if (pos != string::npos) {
        cout << "\"World\" found in str1 at index: " << pos << endl;
    }
    else {
        cout << "\"World\" not found in str1." << endl;
    }

    // 2. Inserting and Erasing
    cout << "\n2. Inserting and Erasing:" << endl;
    str1.insert(7, "Beautiful "); // Insert at position 7
    cout << "str1 after insertion: " << str1 << endl;
    str1.erase(7, 10); // Erase 10 characters starting from position 7
    cout << "str1 after erasing: " << str1 << endl;

    // 3. Replacing
    cout << "\n3. Replacing:" << endl;
    str1.replace(7, 5, "Universe"); // Replace "World" with "Universe"
    cout << "str1 after replacement: " << str1 << endl;

    // 4. Concatenation
    cout << "\n4. Concatenation:" << endl;
    string concatenated = str1 + " - " + str2;
    cout << "Concatenated string: " << concatenated << endl;

    // 5. Swapping
    cout << "\n5. Swapping:" << endl;
    str1.swap(str2);
    cout << "str1 after swap: " << str1 << endl;
    cout << "str2 after swap: " << str2 << endl;

    // 6. Clearing
    cout << "\n6. Clearing:" << endl;
    str1.clear();
    cout << "str1 after clearing: \"" << str1 << "\"" << endl;

    // 7. Checking if a String is Empty
    cout << "\n7. Checking if a String is Empty:" << endl;
    if (str1.empty()) {
        cout << "str1 is empty." << endl;
    }
    else {
        cout << "str1 is not empty." << endl;
    }

    // 8. Finding the Last Occurrence of a Substring
    cout << "\n8. Finding the Last Occurrence of a Substring:" << endl;
    str1 = "Hello, World! World!";
    pos = str1.rfind("World");
    if (pos != string::npos) {
        cout << "Last occurrence of \"World\" in str1 is at index: " << pos << endl;
    }
    else {
        cout << "\"World\" not found in str1." << endl;
    }

    // 9. Iterating through Characters
    cout << "\n9. Iterating through Characters:" << endl;
    cout << "Characters in str2: ";
    for (char c : str2) {
        cout << c << " ";
    }
    cout << endl;


    // 10. Function to convert string to uppercase
        string result1 = str1;
        for (size_t i = 0; i < result1.size(); ++i) {
            if (result1[i] >= 'a' && result1[i] <= 'z') {
                result1[i] = result1[i] - ('a' - 'A');
            }
        }
        cout << endl << "UPPERCASE: " <<  result1;


    // 11. Function to convert string to lowercase
        string result2 = str2;
        for (size_t i = 0; i < result2.size(); ++i) {
            if (result2[i] >= 'A' && result2[i] <= 'Z') {
                result2[i] = result2[i] + ('a' - 'A');
            }
        }
        cout << endl  << "LOWERCASE: " << result2;
    }

int main() {
    demonstrateAdditionalStringOperations();
    return 0;
}

