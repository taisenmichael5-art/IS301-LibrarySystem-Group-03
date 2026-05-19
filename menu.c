
#include <stdio.h>      // Standard I/O library for printf
#include "menu.h"       // Header file containing menu function declarations

/*
 * displayMenu
 * Prints the available menu options for the library system.
 */
void displayMenu(void) {
    printf("\n========================================\n");   // Print menu header line
    printf("        Library Management Menu\n");           // Print menu title
    printf("========================================\n");   // Print separator line

    // Print numbered menu options
    printf("1.  Display all books\n");
    printf("2.  Search for a book by title or author\n");
    printf("3.  Add a new book\n");
    printf("4.  Update book quantity\n");
    printf("5.  Sort books by title\n");
    printf("6.  Register a member\n");
    printf("7.  View members\n");
    printf("8.  Issue book\n");
    printf("9.  Return book\n");
    printf("10. View borrowing records\n");
    printf("11. Generate inventory report\n");
    printf("12. Exit\n");   // Exit option
}
=======


