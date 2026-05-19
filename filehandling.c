#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "books.h"
#include "members.h"
#include "borrowing.h"

extern Borrowing borrowings[MAX_BORROWINGS];
extern int borrowingCount;

/**
 * Removes the trailing newline character from a string if it exists.
 * Typically used after fgets() to clean up user or file input.
 */
static void removeNewLine(char *text) {
    size_t length = strlen(text);

    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }
}

/**
 * Displays a prompt and reads a string of text from standard input.
 * Ensures the input is null-terminated and the newline is removed.
 */
void readLine(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    removeNewLine(buffer);
}

/**
 * Robustly reads an integer from the user.
 * Loops until the user provides a valid numeric input without extra characters.
 */
int readInt(const char *prompt) {
    char input[30];
    int number;
    char extra;

    while (1) {
        readLine(prompt, input, sizeof(input));
        // Validates that sscanf finds exactly one integer and no leftover chars
        if (sscanf(input, "%d %c", &number, &extra) == 1) {
            return number;
        }
        printf("Please enter a valid whole number.\n");
    }
}

/**
 * Loads book data from a CSV file into the global books array.
 * Parses ID, Title, Author, Genre, Year, and Quantity.
 */
void loadBooksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[300];

    bookCount = 0; // Reset count before loading

    if (file == NULL) {
        printf("books.txt was not found. A new file will be created when books are saved.\n");
        return;
    }

    /* Process file line by line until EOF or array capacity is reached */
    while (fgets(line, sizeof(line), file) != NULL && bookCount < MAX_BOOKS) {
        Book book;
        char *token;

        removeNewLine(line);
        
        // Tokenize the line using commas as delimiters
        token = strtok(line, ",");
        if (token == NULL) continue;
        strcpy(book.id, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(book.title, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(book.author, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(book.genre, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        book.yearPublished = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        book.quantity = atoi(token);

        books[bookCount] = book;
        bookCount++;
    }

    fclose(file);
}

/**
 * Saves all books currently in memory to the specified CSV file.
 */
void saveBooksToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;

    if (file == NULL) {
        printf("Could not save books to file.\n");
        return;
    }

    for (i = 0; i < bookCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%d,%d\n",
                books[i].id,
                books[i].title,
                books[i].author,
                books[i].genre,
                books[i].yearPublished,
                books[i].quantity);
    }

    fclose(file);
}

/**
 * Loads member registration data from a CSV file.
 * Expects format: ID, Name, Phone.
 */
void loadMembersFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[220];

    memberCount = 0;

    if (file == NULL) {
        printf("members.txt was not found. A new file will be created when members are saved.\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL && memberCount < MAX_MEMBERS) {
        Member member;
        char *token;

        removeNewLine(line);
        token = strtok(line, ",");
        if (token == NULL) continue;
        strcpy(member.id, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(member.name, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(member.phone, token);

        members[memberCount] = member;
        memberCount++;
    }

    fclose(file);
}

/**
 * Saves current members in memory to a CSV file.
 */
void saveMembersToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;

    if (file == NULL) {
        printf("Could not save members to file.\n");
        return;
    }

    for (i = 0; i < memberCount; i++) {
        fprintf(file, "%s,%s,%s\n", members[i].id, members[i].name, members[i].phone);
    }

    fclose(file);
}

/**
 * Loads borrowing history and active status from a CSV file.
 * Handles cases where return dates might be empty.
 */
void loadBorrowingsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[300];

    borrowingCount = 0; // Reset count before loading

    if (file == NULL) {
        printf("borrowings.txt was not found. A new file will be created when borrowings are saved.\n");
        return;
    }

    /* Process file line by line until EOF or array capacity is reached */
    while (fgets(line, sizeof(line), file) != NULL && borrowingCount < MAX_BORROWINGS) {
        Borrowing borrowing;
        char *token;

        removeNewLine(line);
        
        // Tokenize the line using commas as delimiters
        token = strtok(line, ",");
        if (token == NULL) continue;
        borrowing.recordId = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(borrowing.bookId, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(borrowing.memberId, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(borrowing.borrowDate, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(borrowing.dueDate, token);

        /* Logic for returnDate: If the field is missing, it sets a default '-' 
           indicating the book is still currently borrowed. */
        token = strtok(NULL, ",");
        if (token == NULL) {
            strcpy(borrowing.returnDate, "-");
            borrowing.returned = 0;
        } else {
            strcpy(borrowing.returnDate, token);
            token = strtok(NULL, ",");
            borrowing.returned = (token == NULL) ? 0 : atoi(token);
        }

        borrowings[borrowingCount] = borrowing;
        borrowingCount++;
    }

    fclose(file);
}

/**
 * Saves current borrowing transactions to a data file.
 */
void saveBorrowingsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;

    if (file == NULL) {
        printf("Could not save borrowing records to file.\n");
        return;
    }

    for (i = 0; i < borrowingCount; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d\n",
                borrowings[i].recordId,
                borrowings[i].bookId,
                borrowings[i].memberId,
                borrowings[i].borrowDate,
                borrowings[i].dueDate,
                borrowings[i].returnDate,
                borrowings[i].returned);
    }

    fclose(file);
}

/**
 * Processes current data to create a formatted inventory report file.
 */
void generateInventoryReport(const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;
    int totalCopies = 0;

    if (file == NULL) {
        printf("Could not create inventory report.\n");
        return;
    }

    // Write headers with specific alignment (negative numbers indicate left-alignment)
    fprintf(file, "Library Inventory Report\n");
    fprintf(file, "========================\n\n");
    fprintf(file, "%-10s %-28s %-22s %-16s %-6s %-8s\n",
            "Book ID", "Title", "Author", "Genre", "Year", "Qty");
    fprintf(file, "------------------------------------------------------------------------------------------\n");

    /* Iterates through all books and writes them to the report. */
    for (i = 0; i < bookCount; i++) {
        fprintf(file, "%-10s %-28s %-22s %-16s %-6d %-8d\n",
                books[i].id,
                books[i].title,
                books[i].author,
                books[i].genre,
                books[i].yearPublished,
                books[i].quantity);
        totalCopies += books[i].quantity;
    }

    // Write summary statistics at the bottom
    fprintf(file, "\nTotal book titles: %d\n", bookCount);
    fprintf(file, "Total available copies: %d\n", totalCopies);
    fprintf(file, "Registered members: %d\n", memberCount);
    fprintf(file, "Borrowing records: %d\n", borrowingCount);

    fclose(file);
    printf("Inventory report generated successfully in %s.\n", filename);
}