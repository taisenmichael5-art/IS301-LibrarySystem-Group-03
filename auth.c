#include <stdio.h>          // Standard I/O library for printf
#include <string.h>         // String functions like strcmp
#include "auth.h"           // Header file for authentication functions
#include "filehandling.h"   // Header file for input handling (e.g., readLine)

/*
 * auth.c
 * Handles administrator authentication for the library system.
 * Uses a simple fixed username/password combination for access.
 */

/*
 * Prompt for login credentials and verify administrator access.
 * Returns 1 if login succeeds, otherwise returns 0 after 3 failed attempts.
 */
int login(void) {
    char username[30];   // Buffer to store entered username
    char password[30];   // Buffer to store entered password
    int attempts;        // Counter for login attempts

    // Display login header
    printf("========================================\n");
    printf("      Library Management System Login\n");
    printf("========================================\n");

    // Allow up to 3 login attempts
    for (attempts = 1; attempts <= 3; attempts++) {
        readLine("Username: ", username, sizeof(username));   // Prompt for username
        readLine("Password: ", password, sizeof(password));   // Prompt for password

        // Check if entered credentials match the fixed admin account
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
            printf("\nLogin successful. Welcome, administrator!\n");
            return 1;   // Successful login
        }

        // Show remaining attempts if login fails
        printf("\nInvalid login. Attempts remaining: %d\n", 3 - attempts);
    }

    return 0;   // Return 0 if all attempts fail
}