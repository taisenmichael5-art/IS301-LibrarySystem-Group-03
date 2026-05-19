# 📚 Library Management System – User Manual

# 👨‍💻 Program Developers

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

# 🖥️ System Requirements

Before running the program, ensure the following are installed:

- Windows/Linux operating system
- GCC Compiler (MinGW for Windows)
- Terminal or Command Prompt
- Git (optional for repository management)

---

## How to Compile the Program

### Using GCC

```bash
gcc main.c books.c members.c borrowing.c auth.c filehandling.c menu.c -o library_system
```

---

## How to Run the Program

### Windows

```bash
library_system.exe
```

### Linux/Mac

```bash
./library_system
```

---

## Login Instructions

1. Run the program.
2. Enter administrator username.
3. Enter password.
4. Access the main menu.

---

## Main Menu Display

<img width="397" height="482" alt="Screenshot 2026-05-19 015532" src="https://github.com/user-attachments/assets/71f80ec1-6c1f-4476-b5d1-b033e4b78ffe" />


---

## Generating Inventory Report

1. Select “Generate Inventory Report”.
2. The system creates inventory_report.txt.
3. Open the file to view the report.

<img width="837" height="343" alt="Screenshot 2026-05-19 020038" src="https://github.com/user-attachments/assets/315e41aa-c806-43fb-a4a7-01b3e81645bf" />


---

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Program does not compile | Check GCC installation |
| File not found | Ensure txt files exist |
| Invalid input | Enter correct values |
| Login failed | Verify username/password |

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

