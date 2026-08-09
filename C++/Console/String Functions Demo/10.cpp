#include <iostream>
#include <string>

using namespace std;

void demonstrateStringOperations() {
    // 1. Initialization and Assignment
    string str1 = "Hello, World!";
    string str2("C++ String Library");
    string str3 = str1; // Copy constructor

    cout << "1. Initialization and Assignment:" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3 (copied from str1): " << str3 << endl;

    // 2. Accessing Characters
    cout << "\n2. Accessing Characters:" << endl;
    cout << "First character of str1: " << str1[0] << endl;
    cout << "Last character of str1: " << str1[str1.length() - 1] << endl;

    // 3. Substrings
    string substr = str1.substr(7, 5); // Starting at index 7, length 5
    cout << "\n3. Substrings:" << endl;
    cout << "Substring of str1 from index 7 with length 5: " << substr << endl;

    // 4. Searching
    size_t found = str2.find("String");
    cout << "\n4. Searching:" << endl;
    if (found != string::npos) {
        cout << "\"String\" found at index: " << found << endl;
    }
    else {
        cout << "\"String\" not found in str2." << endl;
    }

    // 5. Modifying Strings
    str1.replace(7, 5, "Universe"); // Replace "World" with "Universe"
    str2.append(" - Let's learn!"); // Append a string
    cout << "\n5. Modifying Strings:" << endl;
    cout << "str1 after replacement: " << str1 << endl;
    cout << "str2 after append: " << str2 << endl;

    // 6. Comparing Strings
    cout << "\n6. Comparing Strings:" << endl;
    if (str1 == str3) {
        cout << "str1 and str3 are equal." << endl;
    }
    else {
        cout << "str1 and str3 are not equal." << endl;
    }

    if (str1.compare(str2) < 0) {
        cout << "str1 is less than str2." << endl;
    }
    else {
        cout << "str1 is not less than str2." << endl;
    }

    // 7. String Conversion
    int number = 123;
    string numberStr = to_string(number);
    cout << "\n7. String Conversion:" << endl;
    cout << "Integer 123 converted to string: " << numberStr << endl;

    // Convert string back to integer
    int convertedNumber = stoi(numberStr);
    cout << "String \"" << numberStr << "\" converted back to integer: " << convertedNumber << endl;

    // 8. String Length
    cout << "\n8. String Length:" << endl;
    cout << "Length of str1: " << str1.length() << endl;
    cout << "Length of str2: " << str2.length() << endl;
}

int main() {
    demonstrateStringOperations();
    return 0;
}
