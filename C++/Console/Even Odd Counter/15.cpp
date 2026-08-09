#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Define a maximum size for the array

int main() {
    // Ask the user how many numbers they want to enter
    int count;
    cout << "How many numbers do you want to enter (up to " << MAX_SIZE << ")? ";
    cin >> count;

    // Use the ? symbol to ensure count is valid and within the max size
    count = (count > 0 && count <= MAX_SIZE) ? count : 1;

    // Initialize an array to store the user's numbers
    int numbers[MAX_SIZE] = { 0 }; // Initialize with zeros

    // Get numbers from the user
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Variables to count even and odd numbers
    auto evenCount = 0;
    auto oddCount = 0;

    // Check each number if it's even or odd using range-based for loop
    cout << "\nChecking if numbers are even or odd...\n";
    for (int i = 0; i < count; i++) {
        // Determine if the number is even or odd
        string type = (numbers[i] % 2 == 0) ? "even" : "odd";
        cout << numbers[i] << " is " << type << endl;

        // Count even and odd numbers
        if (numbers[i] % 2 == 0) {
            evenCount++;
        }
        else {
            oddCount++;
        }
    }

    // Display counts and custom message
    cout << "\nTotal even numbers: " << evenCount << endl;
    cout << "Total odd numbers: " << oddCount << endl;

    // Use the ? symbol to display a custom message based on even numbers
    string message = (evenCount > oddCount) ? "There are more even numbers than odd numbers!" : "There are more odd numbers than even numbers.";
    cout << message << endl;

    return 0;
}
