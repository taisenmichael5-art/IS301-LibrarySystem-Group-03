
#include <stdio.h>              // Standard I/O library for printf, etc.
#include "auth.h"               // Handles login/authentication functions
#include "books.h"              // Functions for managing books
#include "members.h"            // Functions for managing library members
#include "borrowing.h"          // Functions for issuing/returning books
#include "filehandling.h"       // Functions for saving/loading data from files
#include "menu.h"               // Functions for displaying and handling menu options

/*
 * main.c
 * Entry point for the library management system.
 * Handles startup authentication, data loading, the menu loop, and save-on-exit.
 */
int main(void) {
    int choice; // Variable to store user’s menu choice

    /* The program starts with administrator authentication. */
    if (!login()) {  
        printf("\nAccess denied. Program closed.\n");  
        return 0; // Exit if login fails
    }

    /* Load existing data from the corresponding text files. */
    loadBooksFromFile("books.txt");        // Load book records
    loadMembersFromFile("members.txt");    // Load member records
    loadBorrowingsFromFile("borrowings.txt"); // Load borrowing records

    do {
        displayMenu(); // Show menu options
        choice = readInt("Enter your choice: "); // Read user input

        switch (choice) {
            case 1:
                displayAllBooks(); // Show all books
                break;
            case 2:
                searchBook(); // Search for a book
                break;
            case 3:
                addBook(); // Add a new book
                break;
            case 4:
                updateQuantity(); // Update book quantity
                break;
            case 5:
                sortBooksByTitle(); // Sort books alphabetically
                break;
            case 6:
                registerMember(); // Register a new member
                break;
            case 7:
                viewMembers(); // View all members
                break;
            case 8:
                issueBook(); // Issue a book to a member
                break;
            case 9:
                returnBook(); // Return a borrowed book
                break;
            case 10:
                viewBorrowings(); // View borrowing records
                break;
            case 11:
                generateInventoryReport("inventory_report.txt"); // Create inventory report
                break;
            case 12:
                /* Save all current data before exiting the application. */
                saveBooksToFile("books.txt");        // Save book records
                saveMembersToFile("members.txt");    // Save member records
                saveBorrowingsToFile("borrowings.txt"); // Save borrowing records
                printf("\nAll data saved. Thank you for using the system.\n");
                break;
            default:
                printf("\nInvalid choice. Please choose from 1 to 12.\n");
                break;
        }
    } while (choice != 12); // Loop until user chooses to exit

    return 0; // End of program
}

