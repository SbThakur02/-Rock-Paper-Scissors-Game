#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // Required for seeding the random number generator
#include <ctype.h>  // Required for tolower()

// Function to get the name of the choice from its number
const char* getChoiceName(int choice) {
    switch (choice) {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
        default:
            return "Invalid Choice";
    }
}

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int playerChoice, computerChoice;
    char playAgain;

    // Seed the random number generator with the current time
    // This ensures that the computer's choice is different each time you run the program
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("------------------------------------\n");

    do {
        // --- Get Player's Choice ---
        printf("\nPlease make your choice:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1-3): ");
        
        // Input validation loop
        while (scanf("%d", &playerChoice) != 1 || playerChoice < 1 || playerChoice > 3) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
            // Clear the input buffer in case the user entered non-numeric data
            while (getchar() != '\n'); 
        }

        // --- Get Computer's Choice ---
        // Generate a random number between 1 and 3
        computerChoice = (rand() % 3) + 1;

        // --- Display Choices ---
        printf("\nYou chose:     %s\n", getChoiceName(playerChoice));
        printf("Computer chose: %s\n", getChoiceName(computerChoice));
        printf("\n");

        // --- Determine the Winner ---
        if (playerChoice == computerChoice) {
            printf("It's a TIE!\n");
        } else if ((playerChoice == 1 && computerChoice == 3) || // Rock crushes Scissors
                   (playerChoice == 2 && computerChoice == 1) || // Paper covers Rock
                   (playerChoice == 3 && computerChoice == 2)) { // Scissors cuts Paper
            printf("You WIN this round!\n");
            playerScore++;
        } else {
            printf("Computer WINS this round!\n");
            computerScore++;
        }

        // --- Display Scorecard ---
        printf("\n--- SCOREBOARD ---\n");
        printf("You: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);
        printf("------------------\n");

        // --- Ask to Play Again ---
        printf("\nDo you want to play another round? (y/n): ");
        // Note the space before %c to consume any leftover newline characters
        scanf(" %c", &playAgain);

    } while (tolower(playAgain) == 'y');

    printf("\nThanks for playing!\n");
    printf("Final Score -> You: %d | Computer: %d\n", playerScore, computerScore);

    return 0;
}