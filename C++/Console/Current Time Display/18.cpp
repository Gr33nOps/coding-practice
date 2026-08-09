#include <iostream>   // For input and output
#include <chrono>     // For time-related functions

using namespace std;   // To avoid typing std:: everywhere
using namespace chrono; // To avoid typing chrono:: everywhere

int main() {
    // 1. Get the current time
    // The system clock gives us the current time and date.
    system_clock::time_point currentTime = system_clock::now();

    // 2. Convert the current time to a simpler format
    // This converts the current time into a format that is easier to work with.
    auto timeInSeconds = system_clock::to_time_t(currentTime);

    // 3. Convert the time into a readable string
    // We need a place to store the readable time string.
    char timeString[26]; // Enough space to hold the time string
    // Convert the time to a string and store it in timeString
    ctime_s(timeString, sizeof(timeString), &timeInSeconds);

    // 4. Display the time on the screen
    // Print the readable time string
    cout << "Current time: " << timeString;

    return 0; // End of the program
}
