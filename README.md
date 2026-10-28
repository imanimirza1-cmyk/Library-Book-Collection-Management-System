# Library Book Collection Management System

A menu-driven C++ console application that manages a library's book collection using a **general-purpose singly linked list**. Built for **Lab 05: Implementation of a General-Purpose Linked List**.

Each book is a node storing its ID, title, and a pointer to the next node. The collection grows and shrinks dynamically, and a librarian can insert, remove, swap, sort, and reverse books without shifting array elements.

## Features

- Display all books with their index, ID, and title
- Insert a book at the head or at any index
- Remove a book from the head or from any index
- Swap two books by index
- Sort books by ID (ascending)
- Reverse the collection
- Check whether the collection is empty
- Input validation for menu choices, IDs, and indexes
- Starts with five predefined books for quick testing

## Project Structure

```
.
├── LinkedList.h   # BookNode struct, LinkedList class, CreateBook() helper
├── main.cpp       # Menu-driven console program
└── README.md
```

## Linked List Operations

| Method | Description |
|---|---|
| `Insert(book)` | Insert a node at the head |
| `Remove()` | Remove and return the head node |
| `InsertAt(book, index)` | Insert at an index (out-of-range index is corrected) |
| `RemoveAt(index)` | Remove and return the node at an index (out-of-range index is corrected) |
| `Swap(index1, index2)` | Swap the book data at two valid indexes |
| `Sort()` | Sort by book ID in ascending order |
| `Reverse()` | Reverse the list by re-linking the nodes |
| `Print()` | Display all books and the total count |
| `IsEmpty()` / `IsNotEmpty()` | Check whether the list has any books |
| `GetCount()` | Return the number of books |

The class also follows the Rule of Three: a copy constructor, an assignment operator, and a destructor that releases all nodes.

## Requirements

- A C++ compiler with C++11 support or later (g++, clang++, or MSVC)
- Optional: [Visual Studio Code](https://code.visualstudio.com/) with the Microsoft **C/C++** extension

Check that your compiler is installed:

```bash
g++ --version
```

## Build and Run

Clone the repository and move into its folder:

```bash
git clone <your-repository-url>
cd <repository-folder>
```

Compile:

```bash
g++ -std=c++11 main.cpp -o library
```

Run:

| Platform | Command |
|---|---|
| Windows (PowerShell) | `.\library.exe` |
| Windows (Command Prompt) | `library.exe` |
| macOS / Linux | `./library` |

## Running in VS Code

1. Open the project folder with **File → Open Folder**.
2. Open the terminal with `` Ctrl+` ``.
3. Run the compile command above.
4. Run the executable.

Keep `main.cpp` and `LinkedList.h` in the same folder, because `main.cpp` includes the header with `#include "LinkedList.h"`.

## Menu

```
========================================
   LIBRARY BOOK COLLECTION SYSTEM
========================================
1.  Display All Books
2.  Insert Book at Head
3.  Remove Book from Head
4.  Insert Book at Index
5.  Remove Book at Index
6.  Swap Books
7.  Sort Books by ID
8.  Reverse Book Collection
9.  Check Collection Status
10. Exit
Enter your choice:
```

## Sample Output

Choosing option 1 with the predefined books:

```
Index   Book ID Title
-----------------------------------
0       103     Operating Systems
1       101     Data Structures
2       105     Computer Networks
3       102     Database Systems
4       104     Software Engineering
Total books: 5
```

After choosing option 7 (Sort Books by ID):

```
Index   Book ID Title
-----------------------------------
0       101     Data Structures
1       102     Database Systems
2       103     Operating Systems
3       104     Software Engineering
4       105     Computer Networks
Total books: 5
```

## Why a Linked List?

A fixed-size array needs elements shifted whenever a book is inserted or removed in the middle. A linked list only re-links a few pointers, and it can grow dynamically as the library acquires new books.

| Operation | Array | Singly Linked List |
|---|---|---|
| Insert at head | O(n) (shift) | O(1) |
| Remove from head | O(n) (shift) | O(1) |
| Insert / remove at index | O(n) (shift) | O(n) (traverse), no shifting |
| Access by index | O(1) | O(n) |

## Notes

- `Swap()` and `Sort()` exchange the data stored in nodes (ID and title) rather than re-linking the nodes themselves.
- Indexes are zero-based.
- Memory for removed nodes is released with `delete` in `main.cpp`, and the destructor frees any remaining nodes when the program ends.

## Part B: Individual Project

Part B of the lab applies the same linked list design to a different real-world problem. To adapt this code, change the `BookNode` fields and `CreateBook()` in `LinkedList.h`, then write a new `main.cpp` that demonstrates it with your project's data.

## Author

ABDUL REHMAN
AI / ADP  
UNIVERSITY  Of ENGINEERING & TECHNOLOGY,LAHORE

## License

This project was created for educational purposes as part of a university lab assignment.
