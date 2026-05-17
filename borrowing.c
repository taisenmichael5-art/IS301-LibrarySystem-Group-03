#include <stdio.h>      // Standard input/output functions (printf, etc.)
#include <string.h>     // String handling functions (strcpy, etc.)
#include "borrowing.h"  // Borrowing structure and constants
#include "books.h"      // Book data and functions
#include "members.h"    // Member data and functions
#include "filehandling.h" // File read/write helper functions

// Array to store all borrowing records
Borrowing borrowings[MAX_BORROWINGS];

// Keeps track of how many borrowings are currently stored
int borrowingCount = 0;

// Function to generate the next unique borrowing record ID
static int getNextBorrowingId(void) {
    int i;
    int largestId = 0; // Stores the highest ID found so far

    // Loop through all existing borrowings
    for (i = 0; i < borrowingCount; i++) {
        if (borrowings[i].recordId > largestId) {
            largestId = borrowings[i].recordId; // Update largest ID
        }
    }

    // Return next ID (largest + 1)
    return largestId + 1;
}

// Function to issue (borrow) a book
void issueBook(void) {
    Borrowing newBorrowing; // Temporary structure for new record
    int bookIndex;
    int memberIndex;

    // Check if storage is full
    if (borrowingCount >= MAX_BORROWINGS) {
        printf("\nBorrowing storage is full. Cannot issue another book.\n");
        return;
    }

    printf("\nIssue Book\n");

    // Get Book ID from user
    readLine("Book ID: ", newBorrowing.bookId, sizeof(newBorrowing.bookId));

    // Find book in the books array
    bookIndex = findBookIndexById(newBorrowing.bookId);

    // Validate Book ID
    if (bookIndex == -1) {
        printf("Book ID not found.\n");
        return;
    }

    // Check if book is available in stock
    if (books[bookIndex].quantity <= 0) {
        printf("This book is currently out of stock.\n");
        return;
    }

    // Get Member ID from user
    readLine("Member ID: ", newBorrowing.memberId, sizeof(newBorrowing.memberId));

    // Find member in the members array
    memberIndex = findMemberIndexById(newBorrowing.memberId);

    // Validate Member ID
    if (memberIndex == -1) {
        printf("Member ID not found. Register the member first.\n");
        return;
    }

    // Get borrowing and due dates
    readLine("Borrow date (YYYY-MM-DD): ", newBorrowing.borrowDate, sizeof(newBorrowing.borrowDate));
    readLine("Due date (YYYY-MM-DD): ", newBorrowing.dueDate, sizeof(newBorrowing.dueDate));

    // Assign a unique record ID
    newBorrowing.recordId = getNextBorrowingId();

    // Initialize return information
    strcpy(newBorrowing.returnDate, "-"); // "-" means not yet returned
    newBorrowing.returned = 0;            // 0 = not returned

    /* Borrowing changes two files: borrowings.txt and the book quantity in books.txt. */

    // Store the borrowing record in array
    borrowings[borrowingCount] = newBorrowing;
    borrowingCount++;

    // Reduce book quantity (since it's issued)
    books[bookIndex].quantity--;

    // Save updated data to files
    saveBorrowingsToFile("borrowings.txt");
    saveBooksToFile("books.txt");

    printf("Book issued successfully. Borrowing record ID: %d\n", newBorrowing.recordId);
}

// Function to return a borrowed book
void returnBook(void) {
    int recordId;
    int i;
    int bookIndex;
    char returnDate[DATE_SIZE];

    // Ask user for borrowing record ID
    recordId = readInt("\nEnter borrowing record ID to return: ");

    // Search for the borrowing record
    for (i = 0; i < borrowingCount; i++) {
        if (borrowings[i].recordId == recordId) {

            // Check if already returned
            if (borrowings[i].returned) {
                printf("This borrowing record has already been returned.\n");
                return;
            }

            // Get return date from user
            readLine("Return date (YYYY-MM-DD): ", returnDate, sizeof(returnDate));

            /* Mark the record as returned and add the copy back to inventory. */

            // Update return details
            strcpy(borrowings[i].returnDate, returnDate);
            borrowings[i].returned = 1; // 1 = returned

            // Find the book and increase stock
            bookIndex = findBookIndexById(borrowings[i].bookId);
            if (bookIndex != -1) {
                books[bookIndex].quantity++; // Add book back to stock
            }

            // Save updates to files
            saveBorrowingsToFile("borrowings.txt");
            saveBooksToFile("books.txt");

            printf("Book returned successfully.\n");
            return;
        }
    }

    // If record ID was not found
    printf("Borrowing record ID not found.\n");
}

// Function to display all borrowing records
void viewBorrowings(void) {
    int i;

    // Check if there are no records
    if (borrowingCount == 0) {
        printf("\nNo borrowing records found.\n");
        return;
    }

    // Print table header
    printf("\n%-8s %-10s %-10s %-12s %-12s %-12s %-10s\n",
           "ID", "Book", "Member", "Borrowed", "Due", "Returned", "Status");

    // Print separator line
    printf("--------------------------------------------------------------------------------\n");

    // Loop through all borrowing records and print them
    for (i = 0; i < borrowingCount; i++) {
        printf("%-8d %-10s %-10s %-12s %-12s %-12s %-10s\n",
               borrowings[i].recordId,
               borrowings[i].bookId,
               borrowings[i].memberId,
               borrowings[i].borrowDate,
               borrowings[i].dueDate,
               borrowings[i].returnDate,
               borrowings[i].returned ? "Returned" : "Borrowed"); // Conditional status
    }
}