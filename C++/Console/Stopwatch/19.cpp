/*
#include <iostream>
#include <chrono>
#include <conio.h> // For _getch()

int main() {
    std::cout << "Stopwatch Challenge!\n";
    std::cout << "Your goal is to stop the timer as close to 5 seconds as possible.\n";
    std::cout << "Press any key to start...\n";

    // Wait for the user to press a key to start
    _getch();

    // Start timing
    auto start = std::chrono::steady_clock::now();
    std::cout << "Timer started! Press any key to stop...\n";

    // Wait for the user to press a key to stop
    _getch();

    // End timing
    auto end = std::chrono::steady_clock::now();

    // Calculate the elapsed time
    std::chrono::duration<double> elapsed = end - start;

    // Print the elapsed time and evaluate performance
    std::cout << "You stopped the timer at: " << elapsed.count() << " seconds.\n";

    // Check how close the player was to 5 seconds
    double target = 5.0;
    double difference = std::abs(elapsed.count() - target);

    if (difference <= 0.1) {
        std::cout << "Amazing! You were within 0.1 seconds of 5 seconds!\n";
    }
    else if (difference <= 0.5) {
        std::cout << "Great job! You were within 0.5 seconds of 5 seconds.\n";
    }
    else {
        std::cout << "Keep practicing! You were more than 0.5 seconds off.\n";
    }

    return 0;
}

*/

/*
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main() {
    // Take a snapshot of the time before starting a task
    auto start = steady_clock::now();

    // Simulate a task that takes time (like waiting)
    this_thread::sleep_for(seconds(10));

    // Take another snapshot of the time after finishing the task
    auto end = steady_clock::now();

    // Calculate how long the task took
    // Use duration_cast to convert the duration to seconds as int
    auto elapsed = duration_cast<seconds>(end - start);

    // Print out how many seconds the task took
    cout << "The task took " << elapsed.count() << " seconds.\n";

    return 0;
}

*/


/*
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    char choice;
    bool running = false;
    steady_clock::time_point start, end;

    while (true) {
        // Display menu
        cout << "\nStopwatch Menu:\n";
        cout << "s - Start the stopwatch\n";
        cout << "e - End the stopwatch\n";
        cout << "q - Quit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 's') {
            if (running) {
                cout << "Stopwatch is already running.\n";
            }
            else {
                // Start timing
                start = steady_clock::now();
                running = true;
                cout << "Stopwatch started.\n";
            }
        }
        else if (choice == 'e') {
            if (!running) {
                cout << "Stopwatch is not running. Start it first.\n";
            }
            else {
                // End timing
                end = steady_clock::now();
                running = false;

                // Calculate elapsed time with precision
                auto elapsed = duration_cast<duration<double>>(end - start);

                // Display the elapsed time with precision
                cout << "Elapsed time: " << elapsed.count() << " seconds.\n";
            }
        }
        else if (choice == 'q') {
            if (running) {
                cout << "Stopwatch is still running. Ending it now.\n";
                end = steady_clock::now();
                auto elapsed = duration_cast<duration<double>>(end - start);
                cout << "Final elapsed time: " << elapsed.count() << " seconds.\n";
            }
            cout << "Quitting the program.\n";
            break;
        }
        else {
            cout << "Invalid option. Please enter 's', 'e', or 'q'.\n";
        }
    }

    return 0;
}


*/


#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h> // For _getch()
#include <iomanip> // For formatting output

using namespace std;
using namespace chrono;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string BOLD = "\033[1m";

void displayElapsedTime(milliseconds elapsed) {
    auto hrs = duration_cast<hours>(elapsed);
    auto mins = duration_cast<minutes>(elapsed % hours(1));
    auto secs = duration_cast<seconds>(elapsed % minutes(1));
    auto millis = duration_cast<milliseconds>(elapsed % seconds(1));

    // Clear the current line and move the cursor to the beginning
    cout << "\r" << CYAN << BOLD
        << setw(2) << setfill('0') << hrs.count() << ":"
        << setw(2) << setfill('0') << mins.count() << ":"
        << setw(2) << setfill('0') << secs.count() << "."
        << setw(3) << setfill('0') << millis.count() << " " << RESET;
    cout.flush();
}

void printInstructions() {
    cout << "\n" << BOLD << GREEN << "Stopwatch" << RESET << "\n";
    cout << "----------\n";
    cout << "Press 's' to start\n";
    cout << "Press 'e' to stop\n";
    cout << "Press 'r' to reset\n";
    cout << "Press 'q' to quit\n";
}

int main() {
    char choice;
    bool running = false;
    steady_clock::time_point start;
    steady_clock::time_point stop;
    milliseconds accumulated = milliseconds(0);
    milliseconds elapsed = milliseconds(0);

    printInstructions();

    while (true) {
        if (running) {
            steady_clock::time_point now = steady_clock::now();
            elapsed = duration_cast<milliseconds>(now - start) + accumulated;
            displayElapsedTime(elapsed);
            this_thread::sleep_for(milliseconds(50)); // Update every 50 milliseconds
        }

        if (_kbhit()) {
            choice = _getch(); // Read user input

            if (choice == 's') {
                if (running) {
                    cout << "\n" << RED << "Stopwatch is already running." << RESET << "\n";
                    continue;
                }
                start = steady_clock::now();
                running = true;
                cout << "\n" << GREEN << "Stopwatch started." << RESET << "\n";
            }
            else if (choice == 'e') {
                if (!running) {
                    cout << "\n" << RED << "Stopwatch is not running." << RESET << "\n";
                    continue;
                }
                stop = steady_clock::now();
                accumulated += duration_cast<milliseconds>(stop - start);
                running = false;
                displayElapsedTime(accumulated);
                cout << "\n" << YELLOW << "Stopwatch stopped." << RESET << "\n";
            }
            else if (choice == 'r') {
                if (running) {
                    cout << "\n" << RED << "Stopwatch is running. Stop it before resetting." << RESET << "\n";
                    continue;
                }
                accumulated = milliseconds(0);
                cout << "\n" << YELLOW << "Stopwatch reset." << RESET << "\n";
                displayElapsedTime(accumulated);
            }
            else if (choice == 'q') {
                if (running) {
                    stop = steady_clock::now();
                    accumulated += duration_cast<milliseconds>(stop - start);
                    running = false;
                    displayElapsedTime(accumulated);
                    cout << "\n" << MAGENTA << "Final elapsed time before quitting." << RESET << "\n";
                }
                break;
            }
            else {
                cout << "\n" << RED << "Invalid option. Please try again." << RESET << "\n";
            }
        }
    }

    return 0;
}
