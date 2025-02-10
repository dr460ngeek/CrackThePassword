#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD "Kalium"  // Set your password here
#define MAX_ATTEMPTS 3   // Maximum number of attempts

void showLockScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||              LOCKED           ||\n");
    printf("||     You only have 3 attempts  ||\n");
    printf("===================================\n");
    printf("Hint: I am the other name of Potassium.\n\n");
}

void showUnlockScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||             UNLOCKED          ||\n");
    printf("===================================\n");
    printf("You cracked it!\n\n");
}

void showFailedScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||            ACCESS DENIED      ||\n");
    printf("===================================\n");
    printf("Too many failed attempts! Lock closed.\n\n");
}

int main() {
    char input[20];  // Buffer for user input
    int attempts = 0;

    showLockScreen();

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            showUnlockScreen();
            return 0;  // Exit the program successfully
        } else {
            attempts++;
            printf("Incorrect password! Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    showFailedScreen();
    return 1;  // Exit with failure
}
