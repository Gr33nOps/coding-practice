#include <iostream>
#include <chrono>
#include <thread>
#include <ctime> // Include this for ctime functions

using namespace std;
using namespace std::chrono;

void displayCurrentTime() {
    auto now = system_clock::now();
    auto time = system_clock::to_time_t(now);

    // Using ctime_s to safely format the time
    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &time);
    cout << "Current Time: " << timeStr;
}

void countdown(int secondsDuration) {
    auto start = steady_clock::now();
    auto end = start + seconds(secondsDuration);

    cout << "Countdown started for " << secondsDuration << " seconds!" << endl;
    while (steady_clock::now() < end) {
        auto remaining = duration_cast<seconds>(end - steady_clock::now()).count();
        cout << "\rTime remaining: " << remaining << " seconds" << flush;
        this_thread::sleep_for(seconds(1));
    }
    cout << "\nCountdown finished!" << endl;
}

void measureExecutionTime() {
    auto start = high_resolution_clock::now();

    // Simulate some work
    this_thread::sleep_for(seconds(2));

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " milliseconds" << endl;
}

int main() {
    displayCurrentTime();

    int countdownSeconds;
    cout << "Enter countdown duration in seconds: ";
    cin >> countdownSeconds;
    countdown(countdownSeconds);

    measureExecutionTime();

    return 0;
}