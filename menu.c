#include <stdio.h>      // Standard input and output functions
#include "menu.h"       // Header file for menu functions


/* =========================================================
   DISPLAY MAIN MENU
========================================================= */

/* 
   Displays the main Library Management System menu.
   This menu allows users to choose different system features.
*/
void displayMenu(void) {

    /* Print menu title */
    printf("\n========================================\n");
    printf("        Library Management Menu\n");
    printf("========================================\n");

    /* Book management options */
    printf("1.  Display all books\n");
    printf("2.  Search for a book by title or author\n");
    printf("3.  Add a new book\n");
    printf("4.  Update book quantity\n");
    printf("5.  Sort books by title\n");

    /* Member management options */
    printf("6.  Register a member\n");
    printf("7.  View members\n");

    /* Borrowing management options */
    printf("8.  Issue book\n");
    printf("9.  Return book\n");
    printf("10. View borrowing records\n");

    /* Report generation option */
    printf("11. Generate inventory report\n");

    /* Exit option */
    printf("12. Exit\n");
}