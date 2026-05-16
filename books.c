#include <stdio.h>          // Standard input and output functions
#include <string.h>         // String handling functions
#include <ctype.h>          // Character handling functions like tolower()
#include "books.h"          // Header file for book management
#include "filehandling.h"   // Header file for file handling functions

/* =========================================================
   GLOBAL VARIABLES
========================================================= */

/* Array that stores all books in memory */
Book books[MAX_BOOKS];

/* Keeps track of how many books are currently stored */
int bookCount = 0;


/* =========================================================
   DISPLAY FUNCTIONS
========================================================= */

/* 
   Prints the table heading used when displaying books.
*/
static void printBookHeader(void) {

    printf("\n%-10s %-28s %-22s %-16s %-6s %-8s\n",
           "Book ID", "Title", "Author", "Genre", "Year", "Qty");

    printf("------------------------------------------------------------------------------------------\n");
}


/* 
   Prints information for one single book.
*/
static void printBook(Book book) {

    printf("%-10s %-28s %-22s %-16s %-6d %-8d\n",
           book.id,
           book.title,
           book.author,
           book.genre,
           book.yearPublished,
           book.quantity);
}


/* =========================================================
   STRING HELPER FUNCTIONS
========================================================= */

/* 
   Converts text into lowercase.
   Used for case-insensitive searching.
*/
static void toLowerText(const char *source, char *destination, int size) {

    int i;

    /* Convert each character to lowercase */
    for (i = 0; source[i] != '\0' && i < size - 1; i++) {

        destination[i] = (char)tolower((unsigned char)source[i]);
    }

    /* Add null terminator at the end */
    destination[i] = '\0';
}


/* =========================================================
   DISPLAY ALL BOOKS
========================================================= */

/* 
   Displays all books currently stored in the system.
*/
void displayAllBooks(void) {

    int i;

    /* Check if there are no books */
    if (bookCount == 0) {

        printf("\nNo books found. Add books first or check books.txt.\n");
        return;
    }

    /* Print table heading */
    printBookHeader();

    /* Print every book */
    for (i = 0; i < bookCount; i++) {

        printBook(books[i]);
    }
}


/* =========================================================
   SEARCH BOOK
========================================================= */

/* 
   Searches for books using title or author name.
*/
void searchBook(void) {

    char keyword[BOOK_TEXT_SIZE];
    char lowerKeyword[BOOK_TEXT_SIZE];
    char lowerTitle[BOOK_TEXT_SIZE];
    char lowerAuthor[BOOK_TEXT_SIZE];

    int i;
    int found = 0;

    /* Ask user for search keyword */
    readLine("\nEnter book title or author to search: ",
             keyword,
             sizeof(keyword));

    /* Convert keyword to lowercase */
    toLowerText(keyword, lowerKeyword, sizeof(lowerKeyword));

    /* Print table heading */
    printBookHeader();

    /* Check every book */
    for (i = 0; i < bookCount; i++) {

        /* Convert title and author to lowercase */
        toLowerText(books[i].title, lowerTitle, sizeof(lowerTitle));
        toLowerText(books[i].author, lowerAuthor, sizeof(lowerAuthor));

        /* Search keyword inside title or author */
        if (strstr(lowerTitle, lowerKeyword) != NULL ||
            strstr(lowerAuthor, lowerKeyword) != NULL) {

            printBook(books[i]);
            found = 1;
        }
    }

    /* If nothing was found */
    if (!found) {

        printf("No matching book was found.\n");
    }
}


/* =========================================================
   ADD NEW BOOK
========================================================= */

/* 
   Adds a new book into the system.
*/
void addBook(void) {

    Book newBook;

    /* Check if storage is full */
    if (bookCount >= MAX_BOOKS) {

        printf("\nBook storage is full. Cannot add another book.\n");
        return;
    }

    printf("\nAdd New Book\n");

    /* Get book ID */
    readLine("Book ID: ", newBook.id, sizeof(newBook.id));

    /* Check if book ID already exists */
    if (findBookIndexById(newBook.id) != -1) {

        printf("A book with this ID already exists.\n");
        return;
    }

    /* Get other book details */
    readLine("Title: ", newBook.title, sizeof(newBook.title));
    readLine("Author: ", newBook.author, sizeof(newBook.author));
    readLine("Genre: ", newBook.genre, sizeof(newBook.genre));

    /* Get year published */
    newBook.yearPublished = readInt("Year published: ");

    /* Get quantity */
    newBook.quantity = readInt("Quantity: ");

    /* Prevent negative quantity */
    if (newBook.quantity < 0) {

        printf("Quantity cannot be negative.\n");
        return;
    }

    /* Store new book into array */
    books[bookCount] = newBook;

    /* Increase total number of books */
    bookCount++;

    /* Save updated records into file */
    saveBooksToFile("books.txt");

    printf("Book added and saved successfully.\n");
}


/* =========================================================
   UPDATE BOOK QUANTITY
========================================================= */

/* 
   Updates the quantity of an existing book.
*/
void updateQuantity(void) {

    char bookId[BOOK_ID_SIZE];

    int index;
    int newQuantity;

    /* Ask user for book ID */
    readLine("\nEnter Book ID to update: ",
             bookId,
             sizeof(bookId));

    /* Find book position */
    index = findBookIndexById(bookId);

    /* Check if book exists */
    if (index == -1) {

        printf("Book ID not found.\n");
        return;
    }

    /* Show current quantity */
    printf("Current quantity for \"%s\" is %d.\n",
           books[index].title,
           books[index].quantity);

    /* Ask for new quantity */
    newQuantity = readInt("Enter new quantity: ");

    /* Prevent negative quantity */
    if (newQuantity < 0) {

        printf("Quantity cannot be negative.\n");
        return;
    }

    /* Update quantity */
    books[index].quantity = newQuantity;

    /* Save changes into file */
    saveBooksToFile("books.txt");

    printf("Book quantity updated successfully.\n");
}


/* =========================================================
   SORT BOOKS BY TITLE
========================================================= */

/* 
   Sorts books alphabetically using Bubble Sort.
*/
void sortBooksByTitle(void) {

    int i;
    int j;

    /* Bubble Sort algorithm */
    for (i = 0; i < bookCount - 1; i++) {

        for (j = 0; j < bookCount - i - 1; j++) {

            /* Compare titles alphabetically */
            if (strcmp(books[j].title, books[j + 1].title) > 0) {

                /* Swap books */
                Book temp = books[j];

                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    /* Save sorted books into file */
    saveBooksToFile("books.txt");

    printf("\nBooks sorted by title and saved to books.txt.\n");

    /* Display sorted books */
    displayAllBooks();
}


/* =========================================================
   FIND BOOK BY ID
========================================================= */

/* 
   Searches for a book using its ID.
   Returns the index position if found.
   Returns -1 if not found.
*/
int findBookIndexById(const char *bookId) {

    int i;

    /* Check every book ID */
    for (i = 0; i < bookCount; i++) {

        if (strcmp(books[i].id, bookId) == 0) {

            return i;
        }
    }

    /* Book not found */
    return -1;
}