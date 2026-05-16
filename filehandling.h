#ifndef FILEHANDLING_H
#define FILEHANDLING_H

/**
 * @brief Prompts the user and reads a line of string input.
 * @param prompt The message displayed to the user.
 * @param buffer The character array where the input will be stored.
 * @param size The maximum number of characters to read.
 */
void readLine(const char *prompt, char *buffer, int size);

/**
 * @brief Prompts the user and reads an integer value.
 * @param prompt The message displayed to the user.
 * @return The integer value entered by the user.
 */
int readInt(const char *prompt);

/* --- Persistence Functions --- */

/**
 * @brief Loads the book collection from a specified data file into memory.
 * @param filename The path to the file containing book records.
 */
void loadBooksFromFile(const char *filename);

/**
 * @brief Writes the current book collection from memory to a data file.
 * @param filename The destination path for the book records.
 */
void saveBooksToFile(const char *filename);

/**
 * @brief Loads the member database from a specified data file.
 * @param filename The path to the file containing member records.
 */
void loadMembersFromFile(const char *filename);

/**
 * @brief Writes the current member records to a data file.
 * @param filename The destination path for the member records.
 */
void saveMembersToFile(const char *filename);

/**
 * @brief Loads active borrowing records from a specified data file.
 * @param filename The path to the file containing borrowing history.
 */
void loadBorrowingsFromFile(const char *filename);

/**
 * @brief Writes current borrowing transactions to a data file.
 * @param filename The destination path for the borrowing records.
 */
void saveBorrowingsToFile(const char *filename);

/* --- Reporting --- */

/**
 * @brief Processes current data to create a formatted inventory report file.
 * @param filename The path where the final report will be saved.
 */
void generateInventoryReport(const char *filename);

#endif