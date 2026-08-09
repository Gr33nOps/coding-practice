/*
#include <iostream>

int main() {
    int number;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> number;

        // Check if input failed
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(); // Skip invalid input
            std::cout << "Input failed! Please enter a valid number." << std::endl;
        }
        else {
            std::cout << "You entered: " << number << std::endl;
            break; // Exit the loop if input is successful
        }
    }

    return 0;
}
*/

/*
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;

    // Writing to the string stream
    ss << "The answer is 42";

    // Reading from the string stream
    std::string text;
    int number;
    ss >> text >> number;

    std::cout << text << " " << number << std::endl; // Output: The answer is 42

    return 0;
}

*/

/*

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;

    // Writing to the string stream
    ss << "The answer is 42";

    // Reading from the string stream
    std::string text;
    int number;

    // Read "The"
    ss >> text;
    std::cout << text << " ";

    // Read "answer"
    ss >> text;
    std::cout << text << " ";

    // Read "is"
    ss >> text;
    std::cout << text << " ";

    // Read 42
    ss >> number;
    std::cout << number << std::endl;

    return 0;
}

*/

/*
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;

    // Writing to the string stream
    ss << "The answer is 42";

    // Reading from the string stream
    std::string text;
    int number;

    // Read until the number
    std::getline(ss, text, '4');
    text += '4'; // adding the number part back to the text
    ss >> number;

    std::cout << text << " " << number << std::endl; // Output: The answer is 42

    return 0;
}

*/

/*
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;

    // Writing to the string stream
    ss << "The answer is 42";

    // Reading from the string stream
    std::string text;
    int number;

    // Read the whole line into a string variable
    std::string fullText = ss.str();

    // Use another stringstream to read parts
    std::stringstream fullStream(fullText);
    std::string word;

    // Read words until we find the number
    while (fullStream >> word) {
        if (std::stringstream(word) >> number) {
            break;
        }
        text += word + " ";
    }

    std::cout << text << number << std::endl; // Output: The answer is 42

    return 0;
}

*/

/*
#include <iostream>
#include <sstream>

int main() {
    std::string data = "123 456 789";
    std::istringstream iss(data); // Initialize with the string

    int a, b, c;
    iss >> a >> b >> c; // Extract the numbers from the string

    std::cout << "Numbers: " << a << ", " << b << ", " << c << std::endl; // Output: 123, 456, 789

    return 0;
}

*/

/*
#include <iostream>
#include <sstream>

int main() {
    std::ostringstream oss;

    oss << "Hello, " << "world!" << " The number is " << 42;

    std::string result = oss.str(); // Get the constructed string
    std::cout << result << std::endl; // Output: Hello, world! The number is 42

    return 0;
}

*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    stringstream ss;

    ss << "Hello, " << 2024 << " " << 3.14 << " " << true;

    string text;
    int year;
    double pi;
    bool flag;

    ss >> text >> year >> pi >> flag;

    cout << "String: " << text << endl;
    cout << "Integer: " << year << endl;
    cout << "Double: " << pi << endl;
    cout << "Boolean: " << boolalpha << flag << endl;

    ss.clear();
    ss.str("");
    ss << "The quick brown fox jumps over the lazy dog 12345";

    string fullLine;
    getline(ss, fullLine);

    cout << "Full line: " << fullLine << endl;

    ss.clear();
    ss.str("");
    ss << "The quick brown fox jumps over the lazy dog 12345";

    string partialText;
    int number;

    ss >> partialText;
    getline(ss, fullLine);
    stringstream restStream(fullLine);
    restStream >> number;

    cout << "Partial text: " << partialText << endl;
    cout << "Rest of the line: " << fullLine << endl;
    cout << "Extracted number: " << number << endl;

    return 0;
}

