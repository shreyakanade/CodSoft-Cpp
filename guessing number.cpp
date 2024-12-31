#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   
    srand(time(0));

   
    int secret_number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "I've chosen a random number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secret_number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != secret_number);

    return 0;
}
