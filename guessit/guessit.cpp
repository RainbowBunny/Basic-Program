#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randomize(long long l, long long r) {
    // random number generator with mt19937 algorithm.
    return rng() % (r - l + 1) + l;
}

long long recieveNumber() {

    // This function returns the number that the user has guessed.

    cout << "Please enter a number: ";
    long long guessNumber;
    
    string guessNumberString;
    cin >> guessNumberString;
    
    try {

        guessNumber = stoll(guessNumberString);
    
    }
    catch (invalid_argument const &ex) {
        
        cout << "Error, please enter a valid number!\n";
        return -1;
    }
    catch (out_of_range const &ex) {
        
        cout << "This device can only handle 64 bit integers!\n";
        return -1;

    }

    return guessNumber;
}

string response(long long guessNumber, long long randomNumber) {
    // This function returns the response string of the game after recieved the guessNumber.

    if (guessNumber > randomNumber) {
        return "Your number is too large!";
    } else if (guessNumber < randomNumber) {
        return "Your number is too small!";
    } else {
        return "You guessed right!";
    }

    throw invalid_argument("Something went wrong in the response function!");

}

bool win(long long guessNumber, long long randomNumber) {
    return guessNumber == randomNumber;
}

int main() {
    long long randomNumber = randomize(1, 10);
    while (true) {
        long long guessNumber = recieveNumber();
        
        if (guessNumber == -1) {
            continue;
        }

        cout << response(guessNumber, randomNumber) << endl;

        if (win(guessNumber, randomNumber)) {
            exit(0);
        }
    }
}