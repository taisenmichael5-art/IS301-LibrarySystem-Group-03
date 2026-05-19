# Pseudocode for Library Management System Functions

## `auth.h` / `auth.c`

### `int login(void)`
- Print login banner
- Repeat up to 3 attempts:
  - Prompt and read username
  - Prompt and read password
  - If username == "admin" and password == "admin123":
    - Print success message
    - Return 1
  - Else print invalid login and remaining attempts
- If all attempts fail, return 0

## `books.h` / `books.c`

### `static void printBookHeader(void)`
- Print a formatted table header for book display

### `static void printBook(Book book)`
- Print book fields in one formatted row

### `static void toLowerText(const char *source, char *destination, int size)`
- For each character in source until end or size-1:
  - Convert character to lowercase
  - Store into destination
- Terminate destination with '\0'

### `void displayAllBooks(void)`
- If `bookCount` is 0:
  - Print message that no books are found
  - Return
- Print book header
- Loop through all books and print each book

### `void searchBook(void)`
- Prompt and read the search keyword
- Convert keyword to lowercase
- Print book header
- Set found flag to false
- For each book:
  - Convert book title and author to lowercase
  - If keyword appears in title or author:
    - Print the book
    - Set found flag true
- If not found, print "No matching book was found"

### `void addBook(void)`
- If `bookCount` >= `MAX_BOOKS`:
  - Print storage full message
  - Return
- Prompt and read new book ID
- If a book with that ID already exists:
  - Print duplicate ID message
  - Return
- Prompt and read new book title, author, genre
- Prompt and read new book year published
- Prompt and read new book quantity
- If quantity < 0:
  - Print error and return
- Store new book in books array
- Increment `bookCount`
- Save books to file
- Print success message

### `void updateQuantity(void)`
- Prompt and read book ID
- Find the book index by ID
- If not found:
  - Print not found message
  - Return
- Print current quantity
- Prompt and read new quantity
- If new quantity < 0:
  - Print error and return
- Update book quantity
- Save books to file
- Print success message

### `void sortBooksByTitle(void)`
- For each pair of adjacent books in the array:
  - If the title of the earlier book is greater than the next title:
    - Swap the two books
- Save books to file
- Print sorted message
- Display all books

### `int findBookIndexById(const char *bookId)`
- For each book index from 0 to `bookCount - 1`:
  - If book ID matches `bookId`, return index
- Return -1 if not found

## `members.h` / `members.c`

### `void registerMember(void)`
- If `memberCount` >= `MAX_MEMBERS`:
  - Print storage full message
  - Return
- Prompt and read member ID
- If a member with that ID already exists:
  - Print duplicate ID message
  - Return
- Prompt and read full name and phone number
- Store new member in members array
- Increment `memberCount`
- Save members to file
- Print success message

### `void viewMembers(void)`
- If `memberCount` is 0:
  - Print message that no members are found
  - Return
- Print member table header
- Loop through all members and print each member record

### `int findMemberIndexById(const char *memberId)`
- For each member index from 0 to `memberCount - 1`:
  - If member ID matches `memberId`, return index
- Return -1 if not found

## `borrowing.h` / `borrowing.c`

### `static int getNextBorrowingId(void)`
- Set largestId to 0
- For each borrowing record:
  - If recordId is greater than largestId, update largestId
- Return largestId + 1

### `void issueBook(void)`
- If `borrowingCount` >= `MAX_BORROWINGS`:
  - Print storage full message
  - Return
- Prompt and read book ID
- Find book index by book ID
- If book not found:
  - Print not found message
  - Return
- If book quantity <= 0:
  - Print out of stock message
  - Return
- Prompt and read member ID
- Find member index by member ID
- If member not found:
  - Print register member first message
  - Return
- Prompt and read borrow date and due date
- Generate new borrowing record ID
- Set returnDate to "-" and returned flag to 0
- Add borrowing record to borrowings array
- Increment `borrowingCount`
- Decrease book quantity by 1
- Save borrowings and books to file
- Print success message with record ID

### `void returnBook(void)`
- Prompt and read borrowing record ID
- For each borrowing record:
  - If record ID matches:
    - If already returned:
      - Print already returned message
      - Return
    - Prompt and read return date
    - Set record returnDate and returned flag to 1
    - Find book index by borrowed book ID
    - If book found, increment book quantity
    - Save borrowings and books to file
    - Print success message
    - Return
- If no record found, print not found message

### `void viewBorrowings(void)`
- If `borrowingCount` is 0:
  - Print message that no borrowing records are found
  - Return
- Print borrowing table header
- For each borrowing record:
  - Print record fields and status as "Returned" or "Borrowed"

## `filehandling.h` / `filehandling.c`

### `static void removeNewLine(char *text)`
- If text ends with '\n', replace it with '\0'

### `void readLine(const char *prompt, char *buffer, int size)`
- Print prompt
- Read line from stdin into buffer
- If reading fails, set buffer to empty string
- Remove the newline character from buffer

### `int readInt(const char *prompt)`
- Loop forever:
  - Read a line into a temporary string
  - Parse it as an integer with `sscanf`
  - If parsing succeeded and no extra characters remain, return the integer
  - Print a validation error and repeat

### `void loadBooksFromFile(const char *filename)`
- Open the books file for reading
- Set `bookCount` to 0
- If file does not exist, print warning and return
- While reading each line and bookCount < MAX_BOOKS:
  - Remove newline from line
  - Split line by commas into tokens
  - Parse ID, title, author, genre, year, quantity
  - Store parsed book in books array
  - Increment `bookCount`
- Close file

### `void saveBooksToFile(const char *filename)`
- Open the books file for writing
- If file cannot be opened, print error and return
- For each book record, write a comma-separated line
- Close file

### `void loadMembersFromFile(const char *filename)`
- Open the members file for reading
- Set `memberCount` to 0
- If file does not exist, print warning and return
- While reading each line and memberCount < MAX_MEMBERS:
  - Remove newline from line
  - Split line by commas into tokens
  - Parse member ID, name, phone
  - Store parsed member in members array
  - Increment `memberCount`
- Close file

### `void saveMembersToFile(const char *filename)`
- Open the members file for writing
- If file cannot be opened, print error and return
- For each member record, write a comma-separated line
- Close file

### `void loadBorrowingsFromFile(const char *filename)`
- Open the borrowings file for reading
- Set `borrowingCount` to 0
- If file does not exist, print warning and return
- While reading each line and borrowingCount < MAX_BORROWINGS:
  - Remove newline from line
  - Split line by commas into tokens
  - Parse record ID, book ID, member ID, borrow date, due date, return date, returned flag
  - If return date token is missing, set returnDate to "-" and returned to 0
  - Store parsed borrowing in borrowings array
  - Increment `borrowingCount`
- Close file

### `void saveBorrowingsToFile(const char *filename)`
- Open the borrowings file for writing
- If file cannot be opened, print error and return
- For each borrowing record, write a comma-separated line
- Close file

### `void generateInventoryReport(const char *filename)`
- Open report file for writing
- If file cannot be opened, print error and return
- Write report header lines
- Write table header for all books
- Initialize totalCopies = 0
- For each book:
  - Write book details to report
  - Add quantity to totalCopies
- Write totals for book titles, available copies, registered members, and borrowing records
- Close file
- Print success message

## `menu.h` / `menu.c`

### `void displayMenu(void)`
- Print the library management menu options numbered 1 to 12

## `main.c`

### `int main(void)`
- Declare `choice`
- Call `login()`
- If login fails, print access denied and exit
- Load data from `books.txt`, `members.txt`, and `borrowings.txt`
- Loop until user chooses 12:
  - Display menu
  - Read menu choice
  - Use switch on choice:
    - 1: displayAllBooks
    - 2: searchBook
    - 3: addBook
    - 4: updateQuantity
    - 5: sortBooksByTitle
    - 6: registerMember
    - 7: viewMembers
    - 8: issueBook
    - 9: returnBook
    - 10: viewBorrowings
    - 11: generateInventoryReport("inventory_report.txt")
    - 12: save books, members, borrowings to files and print exit message
    - default: print invalid choice message
- Return 0
