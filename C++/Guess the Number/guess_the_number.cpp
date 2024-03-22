#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int randomNumber, guess, attempts = 0;
    srand(time(0));
    randomNumber = rand() % 100 + 1;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100. You have 5 attempts to guess it.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "Too high!\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Congratulations! You guessed it right in " << attempts << " attempts.\n";
            break;
        }
    } while (attempts < 5);

    if (attempts == 5) {
        std::cout << "Sorry, you've used all your attempts. The number was: " << randomNumber << std::endl;
    }

    return 0;
}
