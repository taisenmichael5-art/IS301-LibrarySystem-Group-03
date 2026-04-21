#include <stdio.h>
#include <string.h>
#include <time.h>

/*
 * Include project header files.
 * borrowing.h  → Borrowing data structures and function prototypes
 * books.h      → Access to book-related definitions (not modified here)
 * members.h    → Access to member-related definitions (not modified here)
 */
#include "borrowing.h"
#include "books.h"
#include "members.h"

/*
 * Global array to store all borrowing records.
 * history[] keeps track of issued and returned books.
 */
BorrowRecord history[MAX_RECORDS];

/*
 * recordCount:
 * Keeps track of how many borrowing records are currently stored.
 */
int recordCount = 0;

/*
 * Helper function: getCurrentDate
 * --------------------------------
 * Retrieves the current system date and formats it
 * as DD-MM-YYYY.
 *
 * This function is declared as static because it is
 * used only inside this file (borrowing.c).
 */
static void getCurrentDate(char date[]) {
    time_t t = time(NULL);           // Get current system time
    struct tm tm = *localtime(&t);   // Convert to local time structure

    // Format and store the date string
    snprintf(date, 11, "%02d-%02d-%04d",
             tm.tm_mday,
             tm.tm_mon + 1,
             tm.tm_year + 1900);
}

/*
 * Function: issueBook
 * -------------------
 * Allows a member to borrow a book.
 * Records the member ID, book ID, issue date,
 * and sets the status to "Borrowed".
 */
void issueBook(void) {
    int memberID, bookID;

    // Check if borrowing records limit has been reached
    if (recordCount >= MAX_RECORDS) {
        printf("Borrowing records full.\n");
        return;
    }

    printf("\n--- Issue Book ---\n");

    // Get member ID from user
    printf("Enter Member ID: ");
    scanf("%d", &memberID);

    // Get book ID from user
    printf("Enter Book ID: ");
    scanf("%d", &bookID);

    /*
     * Check if the book is already borrowed.
     * A book cannot be issued again until it is returned.
     */
    for (int i = 0; i < recordCount; i++) {
        if (history[i].bookID == bookID && history[i].isReturned == 0) {
            printf("Book is already borrowed.\n");
            return;
        }
    }

    // Store borrowing details in the history array
    history[recordCount].memberID = memberID;
    history[recordCount].bookID = bookID;
    history[recordCount].isReturned = 0;  // Book is currently borrowed

    // Set issue date and default return date
    getCurrentDate(history[recordCount].issueDate);
    strcpy(history[recordCount].returnDate, "N/A");

    // Increase the total record count
    recordCount++;

    printf("Book issued successfully.\n");
}

/*
 * Function: returnBook
 * --------------------
 * Allows a member to return a previously borrowed book.
 * Updates the return date and marks the book as returned.
 */
void returnBook(void) {
    int memberID, bookID;
    int found = 0;

    printf("\n--- Return Book ---\n");

    // Get member ID from user
    printf("Enter Member ID: ");
    scanf("%d", &memberID);

    // Get book ID from user
    printf("Enter Book ID: ");
    scanf("%d", &bookID);

    /*
     * Search for the matching borrowing record
     * that has not been returned yet.
     */
    for (int i = 0; i < recordCount; i++) {
        if (history[i].memberID == memberID &&
            history[i].bookID == bookID &&
            history[i].isReturned == 0) {

            // Update return details
            history[i].isReturned = 1;
            getCurrentDate(history[i].returnDate);

            printf("Book returned successfully.\n");
            found = 1;
            break;
        }
    }

    // If no matching record was found
    if (!found) {
        printf("No active borrowing record found.\n");
    }
}

/*
 * Function: displayBorrowingHistory
 * ---------------------------------
 * Displays all borrowing records, including:
 * member ID, book ID, issue date, return date, and status.
 */
void displayBorrowingHistory(void) {
    printf("\n--- Borrowing History ---\n");

    // Display table header
    printf("%-10s %-10s %-15s %-15s %-10s\n",
           "MemberID", "BookID", "Issue Date", "Return Date", "Status");

    /*
     * Loop through all borrowing records and display them.
     */
    for (int i = 0; i < recordCount; i++) {
        printf("%-10d %-10d %-15s %-15s %-10s\n",
               history[i].memberID,
               history[i].bookID,
               history[i].issueDate,
               history[i].returnDate,
               history[i].isReturned ? "Returned" : "Borrowed");
    }
}
