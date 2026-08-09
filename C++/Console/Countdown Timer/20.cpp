#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void countdown(seconds duration) {
    // Get the start time
    auto start = steady_clock::now();
    auto end = start + duration; // Calculate end time based on duration

    while (steady_clock::now() < end) {
        // Calculate the remaining time
        auto now = steady_clock::now();
        auto remaining = duration_cast<seconds>(end - now);

        // Print the remaining time
        cout << "Time left: " << remaining.count() << " seconds" << endl;

        // Wait for 1 second before updating the countdown
        auto next_update = now + seconds(1);
        while (steady_clock::now() < next_update) {
            // Busy wait
        }
    }

    // Final message when time is up
    cout << "Time's up!" << endl;
}

int main() {
    int inputSeconds;

    // Get user input
    cout << "Enter the number of seconds for the countdown: ";
    cin >> inputSeconds;

    // Check for valid input
    if (inputSeconds <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1; // Exit with an error code
    }

    // Define the duration from user input
    seconds userDuration(inputSeconds);

    // Start the countdown
    cout << "Starting countdown..." << endl;
    countdown(userDuration);

    return 0;
}
