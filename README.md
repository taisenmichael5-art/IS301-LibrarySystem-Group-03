# 📚 IS301 Capstone Project – Library Management System (C Program)

## 📌 Submission Method
This project must be submitted through a **GitHub repository link**.  
**ZIP file submission is not allowed.**

---

## 🧑‍🤝‍🧑 Group Repository Setup

Each group must create **one GitHub repository only** for the project.

### Repository naming format
Use this format:

```text
IS301-LibrarySystem-Group-<GroupNumber>
```

Example:

```text
IS301-LibrarySystem-Group-05
```

### Repository visibility
Create the repository as:
- **Private**, then invite the lecturer and all group members
- or **Public**, only if your lecturer instructs you to do so

### Add collaborators
Each group must add:
- all group members
- the lecturer

Go to:

```text
Settings → Collaborators → Add people
```

---

## 🌿 Required Branch Structure

Your repository must contain the following branches:

### 1. `main`
This is the **final submission branch**.  
Do **not** code directly in `main`.

### 2. `develop`
This is the **working integration branch**.  
All completed features must be merged into `develop` first.

### 3. Individual member branches
Each member must create and use their **own branch**.

Use this naming format:

```text
feature/<firstname>-<task>
```

Examples:

```text
feature/john-book-search
feature/mary-member-management
feature/peter-borrow-return
feature/anna-file-handling
```

Each member must work only on their own branch.

---

## 💻 Project Language Requirement

This project is written in **C only**.

Your repository must contain C source files such as:

```text
main.c
book.c
member.c
borrow.c
filehandling.c
```

It may also include header files such as:

```text
book.h
member.h
borrow.h
filehandling.h
```

Do not submit the project in another programming language.

---

## 📁 Suggested C Project Structure

```text
IS301-LibrarySystem-Group-05/
│
├── README.md
├── books.txt
├── inventory_report.txt
├── main.c
├── menu.c
├── menu.h
├── books.c
├── books.h
├── members.c
├── members.h
├── borrowing.c
├── borrowing.h
├── filehandling.c
├── filehandling.h
├── auth.c
├── auth.h
└── docs/
    ├── user_manual.md
    ├── pseudocode.md
    └── flowchart.png
```

You may organise your files slightly differently, but your code must remain clean, modular, and easy to follow.

---

## 🔄 Required GitHub Workflow

Follow these steps correctly.

### Step 1: One member creates the repository
One group member creates the repository on GitHub using the correct naming format.

### Step 2: Create the main branches
After creating the repository, create:

```bash
git branch develop
git push origin develop
```

### Step 3: Each member clones the repository
Each student must clone the repository to their computer:

```bash
git clone https://github.com/your-group/IS301-LibrarySystem-Group-05.git
cd IS301-LibrarySystem-Group-05
```

### Step 4: Switch to develop branch
Before creating your own branch:

```bash
git checkout develop
git pull origin develop
```

### Step 5: Create your feature branch
Each member creates their own branch from `develop`:

```bash
git checkout -b feature/yourname-task
```

Example:

```bash
git checkout -b feature/john-book-search
```

### Step 6: Write and test your C code
Work on your assigned section only.  
Compile and test before committing.

Example compile command:

```bash
gcc main.c books.c members.c borrowing.c filehandling.c auth.c -o library_system
```

Example run command:

```bash
./library_system
```

For Windows (MinGW):

```bash
gcc main.c books.c members.c borrowing.c filehandling.c auth.c -o library_system.exe
library_system.exe
```

### Step 7: Commit your work
Commit regularly with meaningful messages.

```bash
git add .
git commit -m "Added book search function in C"
```

### Step 8: Push your branch
Push your own branch to GitHub:

```bash
git push origin feature/yourname-task
```

### Step 9: Create a Pull Request
Go to GitHub and create a Pull Request from your feature branch into:

```text
develop
```

### Step 10: Merge only after review
After your teammates review the code and confirm it works, merge it into `develop`.

### Step 11: Final merge to main
When the whole system is complete, tested, and ready, merge:

```text
develop → main
```

The `main` branch must contain the final working version for marking.

---

## ✅ Branch Rules

### Allowed
- work on your own branch
- merge completed work into `develop`
- merge final tested version into `main`

### Not allowed
- do not code directly in `main`
- do not push unfinished work into `main`
- do not work directly on another member’s branch
- do not delete other members’ files
- do not submit a ZIP file instead of GitHub

---

## 🧾 Commit Message Examples

Use clear commit messages such as:

```text
Added book display function
Implemented member registration
Fixed file reading bug in books.txt
Updated borrowing record logic
Refactored menu functions
Added authentication validation
```

Avoid unclear messages such as:

```text
update
work
done
final
changes
```

---

## 👥 Example Task Distribution

Each member should take responsibility for a clear module.

### Member 1
- Main menu
- Program flow
- Integration

### Member 2
- Book management
- Search book
- Add new book
- Update quantity

### Member 3
- Member management
- Register members
- View member details
- Update member information

### Member 4
- Borrowing records
- Issue books
- Return books
- Borrowing history

### Member 5
- File handling
- Read from `books.txt`
- Write to `inventory_report.txt`
- Error handling

This is only a guide. Your group may divide tasks differently, but individual contributions must be visible in GitHub.

---

## 📚 Required Files in the Repository

Your repository should include the following:

### Source code files
- `.c` files
- `.h` files

### Data files
- `books.txt`
- `inventory_report.txt` (generated by the program)

### Documentation
- `README.md`
- user manual
- pseudocode and/or flowcharts

---

## 🧪 C Program Testing Expectations

Before submitting, your program should:
- compile without major errors
- run correctly from the terminal
- show a menu-driven interface
- read book data from `books.txt`
- allow search by title or author
- add a new book
- update quantity
- generate `inventory_report.txt`
- handle invalid input properly
- handle file errors properly

---

## 🔐 Recommended Protection for Branches

If possible, protect the `main` branch on GitHub.

Recommended:
- require pull requests before merging
- do not allow direct pushes to `main`

This helps protect the final submission.

---

## 📤 Final Submission

The final submission must include:

### 1. GitHub repository link
Submit the repository link as instructed by the lecturer.

### 2. Final code in `main`
The final working version must be in the `main` branch.

### 3. Evidence of contribution
Each member must have visible commits and branch activity on GitHub.

### 4. Complete project files
The repository must contain:
- C source code
- header files
- books.txt
- generated inventory report
- documentation

---

## ❌ What will not be accepted

The following may lead to penalties:
- submitting a ZIP file instead of GitHub
- no individual member branches
- no visible commits from some members
- direct coding in `main`
- incomplete or non-working C program
- poor file organisation
- missing documentation

---

## 📝 Minimum Git Commands Summary

Useful commands for all students:

```bash
git clone <repo-url>
cd <repo-folder>
git checkout develop
git pull origin develop
git checkout -b feature/yourname-task
git add .
git commit -m "Your clear commit message"
git push origin feature/yourname-task
```

To get latest changes from develop:

```bash
git checkout develop
git pull origin develop
git checkout feature/yourname-task
git merge develop
```

---

## 🚀 Final Reminder

This is a **group C programming project**.  
Marks are not only for the final program, but also for:
- correct GitHub setup
- correct use of branches
- teamwork
- code quality
- documentation
- testing
- final presentation

Start early, commit regularly, and keep your repository organised.
