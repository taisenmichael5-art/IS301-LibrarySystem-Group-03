# 📚 Library Management System – User Manual

# 👨‍💻 Group Members

| Name | Student ID | Responsibility |
|---|---|---|
| Nathaniel Posanai | 240160 | Book Management |
| Abel Wamanimbo | 240569 | Member Management |
| Taisen Marainump | 250692 | Borrowing System |
| Raymond Pae | 240158 | File Handling |
| Raymond Bonaven | 240567 | Main Menu & Integration |

---

## 📖 Project Overview

The Library Management System is a menu-driven C program developed for the IS301 Capstone Project. The system helps librarians manage books, members, and borrowing records using text files for data storage.

The program allows users to:

- Login securely
- View available books
- Search books by title or author
- Add new books
- Register library members
- Borrow books
- Return books
- Generate inventory reports
- Save and load data using files

---

# 🔄 Program Flow

1. User logs into the system
2. Program loads book data from file
3. Main menu is displayed
4. User selects an option
5. Requested operation is performed
6. Data is updated and saved
7. Program continues until Exit is selected

---

# 📁 Project Files

Main project files include:

| File Name | Description |
|---|---|
| `main.c` | Main program execution |
| `menu.c` | Menu display and navigation |
| `books.c` | Book management functions |
| `members.c` | Member management functions |
| `borrowing.c` | Borrow and return functions |
| `filehandling.c` | File reading and writing |
| `auth.c` | User authentication |
| `books.txt` | Book database |
| `inventory_report.txt` | Generated inventory report |

---

# 🛠 System Limitations

Current limitations include:

- Text-file storage only
- Single administrator login
- No graphical user interface
- Limited validation for special characters
- Maximum storage depends on array size

---

# 🚀 Future Improvements

Possible future upgrades include:

- Database integration using MySQL
- Graphical User Interface (GUI)
- Multiple user roles
- Online borrowing system
- Automatic overdue notifications
- Improved search filtering

---

# 🖥️ System Requirements

Before running the program, ensure the following are installed:

- GCC Compiler (MinGW for Windows)
- Terminal or Command Prompt
- Git (optional for repository management)

---

# ⚙️ Compiling the Program

## For Linux / macOS

```bash
gcc main.c books.c members.c borrowing.c filehandling.c auth.c -o library_system