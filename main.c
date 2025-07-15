#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> // Include for boolean type
#include <conio.h> // For clscr();

void playGame(int *score, int *attempts) {
    int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    *attempts = 0; // Initialize attempts

    printf("Guess the number (between 1 and 100):\n");

    while (1) {
        printf("Enter your guess: ");
        // Check if the input is valid
        if (scanf("%d", &guess) != 1) {
            // Clear the input buffer
            while (getchar() != '\n'); // Discard invalid input

            clearScreen();
            printf("Invalid input. Please enter a valid number between 1 and 100.\n");
            continue; // Prompt for input again
        }

        (*attempts)++; // Increment attempts

        if (guess < 1 || guess > 100) {
                clearScreen();
            printf("Please enter a valid number between 1 and 100.\n");
        } else if (guess < numberToGuess) {
            clearScreen();
            printf("Too low! Try again.\n");
        } else if (guess > numberToGuess) {
            clearScreen();
            printf("Too high! Try again.\n");
        } else {
            clearScreen()
;            printf("Congratulations! You've guessed the number %d in %d attempts.\n", numberToGuess, *attempts);
            *score += 10;
            printf("Your new score is: %d\n", *score);
            break; // Exit the loop when the guess is correct
        }
    }
}

void clearScreen() {
    #ifdef _WIN32
        // For Windows
        system("cls");
    #else
        // For Unix/Linux and macOS
        system("clear");
    #endif
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int score = 0;
    int attempts = 0;
    char playAgain;

    do {
        playGame(&score, &attempts); // Pass score and attempts by reference
        printf("Your current score: %d\n", score);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); // Space before %c to consume any leftover newline
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! Your final score: %d\n", score);
    system("PAUSE");
}
