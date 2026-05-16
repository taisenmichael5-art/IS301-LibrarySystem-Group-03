#include <stdio.h>              // Standard input and output functions

#include "auth.h"               // Authentication functions
#include "books.h"              // Book management functions
#include "members.h"            // Member management functions
#include "borrowing.h"          // Borrowing management functions
#include "filehandling.h"       // File handling functions
#include "menu.h"               // Menu display functions


/* =========================================================
   MAIN FUNCTION
========================================================= */

/* 
   Program execution starts here.
*/
int main(void) {

    int choice;


    /* =====================================================
       ADMINISTRATOR LOGIN
    ===================================================== */

    /*
       The system first checks if the administrator
       enters correct login credentials.
    */
    if (!login()) {

        printf("\nAccess denied. Program closed.\n");
        return 0;
    }


    /* =====================================================
       LOAD DATA FROM FILES
    ===================================================== */

    /*
       Load saved data from text files into arrays
       before the menu starts.
    */
    loadBooksFromFile("books.txt");
    loadMembersFromFile("members.txt");
    loadBorrowingsFromFile("borrowings.txt");


    /* =====================================================
       MAIN MENU LOOP
    ===================================================== */

    /*
       Keep displaying the menu until the user chooses Exit.
    */
    do {

        /* Display menu options */
        displayMenu();

        /* Get user menu choice */
        choice = readInt("Enter your choice: ");


        /* =================================================
           PROCESS USER CHOICE
        ================================================= */

        switch (choice) {

            /* Display all books */
            case 1:
                displayAllBooks();
                break;

            /* Search for a book */
            case 2:
                searchBook();
                break;

            /* Add a new book */
            case 3:
                addBook();
                break;

            /* Update quantity of a book */
            case 4:
                updateQuantity();
                break;

            /* Sort books alphabetically */
            case 5:
                sortBooksByTitle();
                break;

            /* Register a new member */
            case 6:
                registerMember();
                break;

            /* View all registered members */
            case 7:
                viewMembers();
                break;

            /* Issue a book to a member */
            case 8:
                issueBook();
                break;

            /* Return a borrowed book */
            case 9:
                returnBook();
                break;

            /* Display borrowing records */
            case 10:
                viewBorrowings();
                break;

            /* Generate inventory report */
            case 11:
                generateInventoryReport("inventory_report.txt");
                break;

            /* Exit the program */
            case 12:

                /*
                   Save all updated data back into text files
                   before closing the system.
                */
                saveBooksToFile("books.txt");
                saveMembersToFile("members.txt");
                saveBorrowingsToFile("borrowings.txt");

                printf("\nAll data saved. Thank you for using the system.\n");
                break;

            /* Invalid menu option */
            default:
                printf("\nInvalid choice. Please choose from 1 to 12.\n");
                break;
        }

    } while (choice != 12);


    /* =====================================================
       END OF PROGRAM
    ===================================================== */

    return 0;
}