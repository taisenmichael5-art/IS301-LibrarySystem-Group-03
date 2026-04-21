#ifndef BORROWING_H
#define BORROWING_H
/*
 * Header guard:
 * Prevents this header file from being included more than once
 * during compilation, which avoids redefinition errors.
 */

#define MAX_RECORDS 100
/*
 * MAX_RECORDS:
 * Defines the maximum number of borrowing records
 * that the system can store at one time.
 */

// Structure to store borrowing information
typedef struct {
    int memberID;
    /*
     * memberID:
     * Stores the ID of the member who borrowed the book.
     */

    int bookID;
    /*
     * bookID:
     * Stores the ID of the book that was borrowed.
     */

    char issueDate[11];
    /*
     * issueDate:
     * Stores the date when the book was issued.
     * Format used: DD-MM-YYYY
     * 11 characters are required including the null terminator.
     */

    char returnDate[11];
    /*
     * returnDate:
     * Stores the date when the book was returned.
     * Format used: DD-MM-YYYY
     * If the book has not been returned yet, it stores "N/A".
     */

    int isReturned;
    /*
     * isReturned:
     * Indicates the current borrowing status of the book.
     * Value 0 → Book is currently borrowed
     * Value 1 → Book has been returned
     */

} BorrowRecord;

/*
 * Function Prototypes
 * These functions are implemented in borrowing.c
 */

// Issues a book to a member and records the borrowing details
void issueBook(void);

// Returns a previously borrowed book
void returnBook(void);

// Displays the complete borrowing history
void displayBorrowingHistory(void);

#endif
/*
 * End of BORROWING_H
 */
