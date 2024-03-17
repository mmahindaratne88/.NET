#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, attempts = 0;
    srand(time(0));
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. You have 5 attempts to guess it.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > randomNumber) {
            printf("Too high!\n");
        } else if (guess < randomNumber) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed it right in %d attempts.\n", attempts);
            break;
        }
    } while (attempts < 5);

    if (attempts == 5) {
        printf("Sorry, you've used all your attempts. The number was: %d\n", randomNumber);
    }

    return 0;
}
