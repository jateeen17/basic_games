#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // seed random number generator
    int secretNumber = rand() % 100 + 1; // generate secret number between 1 and 100
    int tries = 0;
    int guess;

    cout << "Welcome to Guess the Number!" << endl;
    cout << "I'm thinking of a number between 1 and 100. You have 7 tries to guess it." << endl;

    do {
        cout << "Guess #" << tries + 1 << ": ";
        cin >> guess;
        tries++;

        if (guess < secretNumber) {
            cout << "Too low! Guess again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Guess again." << endl;
        }
    } while (guess != secretNumber && tries < 7);

    if (guess == secretNumber) {
        cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
    } else {
        cout << "Sorry, you ran out of tries. The secret number was " << secretNumber << "." << endl;
    }

    return 0;
}
