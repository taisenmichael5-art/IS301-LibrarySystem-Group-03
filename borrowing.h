#ifndef BORROWING_H   // Prevents multiple inclusions of this header file
#define BORROWING_H

// Maximum number of borrowing records allowed
#define MAX_BORROWINGS 300

// Maximum length for book ID and member ID strings
#define BORROW_ID_SIZE 20

// Maximum length for date strings (YYYY-MM-DD format, etc.)
#define DATE_SIZE 20

// Structure to store details about a borrowing record
typedef struct {
    int recordId;                         // Unique ID for each borrowing transaction
    char bookId[BORROW_ID_SIZE];          // ID of the borrowed book
    char memberId[BORROW_ID_SIZE];        // ID of the member who borrowed the book
    char borrowDate[DATE_SIZE];           // Date when the book was borrowed
    char dueDate[DATE_SIZE];              // Expected return date
    char returnDate[DATE_SIZE];           // Actual return date ("-" if not returned)
    int returned;                         // Status flag (0 = not returned, 1 = returned)
} Borrowing;

// Declare the borrowing array (defined in another .c file)
extern Borrowing borrowings[MAX_BORROWINGS];

// Keeps track of total number of borrowing records
extern int borrowingCount;

// Function to issue (borrow) a book
void issueBook(void);

// Function to return a borrowed book
void returnBook(void);

// Function to display all borrowing records
void viewBorrowings(void);

#endif
