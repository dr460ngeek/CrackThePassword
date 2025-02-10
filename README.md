# Password Lock Program

## Overview
This is a simple C program that simulates a password-protected lock system. The user is given three attempts to enter the correct password. If the correct password is entered, the program displays a success message. Otherwise, after three failed attempts, access is denied, and the program exits.

## Features
- Simple **text-based UI** with clear messages.
- A **hint** is provided to help users.
- **Three attempts** before locking out the user.
- **Formatted UI** with borders for clarity.

## Code Implementation
```c
#include <stdio.h>
#include <string.h>

#define PASSWORD "1234"  // Set your password here
#define MAX_ATTEMPTS 3   // Maximum number of attempts

void showLockScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||          LOCKED               ||\n");
    printf("===================================\n");
    printf("Hint: The password is a 4-digit number.\n\n");
}

void showUnlockScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||          UNLOCKED             ||\n");
    printf("===================================\n");
    printf("You cracked it!\n\n");
}

void showFailedScreen() {
    printf("\n");
    printf("===================================\n");
    printf("||         ACCESS DENIED         ||\n");
    printf("===================================\n");
    printf("Too many failed attempts! Lock closed.\n\n");
}

int main() {
    char input[20];  
    int attempts = 0;

    showLockScreen();

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            showUnlockScreen();
            return 0;  // Exit successfully
        } else {
            attempts++;
            printf("Incorrect password! Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    showFailedScreen();
    return 1;  // Exit with failure
}
```

## How It Works
1. The program starts and displays the **LOCKED** screen.
2. The user is prompted to enter the password.
3. If the correct password (`1234`) is entered:
   - The program displays **UNLOCKED** and exits successfully.
4. If the wrong password is entered:
   - The user is informed of the incorrect attempt.
   - The number of remaining attempts is displayed.
5. After three failed attempts:
   - The program displays **ACCESS DENIED** and exits.

## Compilation & Execution
### **Compiling with GCC**
Run the following command to compile the program:
```sh
gcc password_lock.c -o password_lock
```

### **Running the Program**
```sh
./password_lock
```
## Conclusion
This C program provides a basic password-protected locking system with a simple user interface. It serves as a foundation for more complex authentication systems.
