#include <iostream>
#include <Windows.h>

#include <ctime>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main() {
    srand(time(0)); 
    char play_again;

    do {
        int number_to_guess = rand() % 100 + 1; 
        int guess;
        int attempts = 0;
        int score = 100; 

        cout << "Welcome to the Enhanced Number Guessing Game!\n";
        cout << "I have selected a number between 1 and 100. Can you guess it?\n";

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            score -= 10; 

            if (guess > number_to_guess) {
                setColor(12);
                cout << "Too high! Try again.\n";
                setColor(7); 
            }
            else if (guess < number_to_guess) {
                setColor(14); 
                cout << "Too low! Try again.\n";
                setColor(7);
            }
            else {
                setColor(10); 
                cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
                cout << "Your score is: " << score << "\n";
                setColor(7); 
            }
        } while (guess != number_to_guess);

        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    cout << "Thank you for playing the game!\n";

    return 0;
}
