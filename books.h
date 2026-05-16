#ifndef BOOKS_H
#define BOOKS_H

/* =========================================================
   CONSTANT DEFINITIONS
========================================================= */

/* Maximum number of books the system can store */
#define MAX_BOOKS 200

/* Maximum size for Book ID */
#define BOOK_ID_SIZE 20

/* Maximum size for text fields like title, author, and genre */
#define BOOK_TEXT_SIZE 80


/* =========================================================
   BOOK STRUCTURE
========================================================= */

/* 
   Structure used to store information about one book.
*/
typedef struct {

    /* Unique ID for the book */
    char id[BOOK_ID_SIZE];

    /* Title of the book */
    char title[BOOK_TEXT_SIZE];

    /* Name of the author */
    char author[BOOK_TEXT_SIZE];

    /* Genre/category of the book */
    char genre[BOOK_TEXT_SIZE];

    /* Year the book was published */
    int yearPublished;

    /* Number of available copies */
    int quantity;

} Book;


/* =========================================================
   GLOBAL VARIABLES
========================================================= */

/* Array that stores all books */
extern Book books[MAX_BOOKS];

/* Keeps track of total number of books */
extern int bookCount;


/* =========================================================
   FUNCTION PROTOTYPES
========================================================= */

/* Displays all books in the system */
void displayAllBooks(void);

/* Searches for a book using title or author */
void searchBook(void);

/* Adds a new book into the system */
void addBook(void);

/* Updates the quantity of a book */
void updateQuantity(void);

/* Sorts books alphabetically by title */
void sortBooksByTitle(void);

/* Finds a book using its ID and returns its index */
int findBookIndexById(const char *bookId);

#endif
