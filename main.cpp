#include <iostream>
#include <string>
#include <limits>
#include "LinkedList.h"
using namespace std;

// Read an integer safely (re-asks until valid input)
int ReadInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

// Read a full line (title may contain spaces)
string ReadTitle()
{
    string title;
    cout << "Enter Book Title: ";
    getline(cin, title);
    return title;
}

void ShowMenu()
{
    cout << "\n========================================\n";
    cout << "   LIBRARY BOOK COLLECTION SYSTEM\n";
    cout << "========================================\n";
    cout << "1.  Display All Books\n";
    cout << "2.  Insert Book at Head\n";
    cout << "3.  Remove Book from Head\n";
    cout << "4.  Insert Book at Index\n";
    cout << "5.  Remove Book at Index\n";
    cout << "6.  Swap Books\n";
    cout << "7.  Sort Books by ID\n";
    cout << "8.  Reverse Book Collection\n";
    cout << "9.  Check Collection Status\n";
    cout << "10. Exit\n";
}

int main()
{
    LinkedList library;

    // Predefined books
    library.InsertAt(CreateBook(103, "Operating Systems"), 0);
    library.InsertAt(CreateBook(101, "Data Structures"), 1);
    library.InsertAt(CreateBook(105, "Computer Networks"), 2);
    library.InsertAt(CreateBook(102, "Database Systems"), 3);
    library.InsertAt(CreateBook(104, "Software Engineering"), 4);

    int choice = 0;

    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
        {
            if (library.IsEmpty())
                cout << "\nThe collection is empty.\n";
            else
                library.Print();
            break;
        }
        case 2:
        {
            int id = ReadInt("Enter Book ID: ");
            string title = ReadTitle();
            library.Insert(CreateBook(id, title));
            cout << "\nBook inserted at head.\n";
            break;
        }
        case 3:
        {
            BookNode* removed = library.Remove();
            if (removed != nullptr)
            {
                cout << "\nRemoved from head: " << removed->title
                     << " (ID " << removed->bookID << ")\n";
                delete removed;
            }
            else
                cout << "\nThe collection is empty. Nothing to remove.\n";
            break;
        }
        case 4:
        {
            int id = ReadInt("Enter Book ID: ");
            string title = ReadTitle();
            int index = ReadInt("Enter index to insert at: ");
            library.InsertAt(CreateBook(id, title), index);
            cout << "\nBook inserted (index is adjusted if out of range).\n";
            break;
        }
        case 5:
        {
            if (library.IsEmpty())
            {
                cout << "\nThe collection is empty. Nothing to remove.\n";
                break;
            }
            int index = ReadInt("Enter index to remove: ");
            BookNode* removed = library.RemoveAt(index);
            if (removed != nullptr)
            {
                cout << "\nRemoved book: " << removed->title
                     << " (ID " << removed->bookID << ")\n";
                delete removed;
            }
            break;
        }
        case 6:
        {
            if (library.GetCount() < 2)
            {
                cout << "\nAt least two books are needed to swap.\n";
                break;
            }
            int i1 = ReadInt("Enter first index: ");
            int i2 = ReadInt("Enter second index: ");
            if (i1 < 0 || i1 >= library.GetCount() ||
                i2 < 0 || i2 >= library.GetCount())
            {
                cout << "\nInvalid index. Valid range is 0 to "
                     << library.GetCount() - 1 << ".\n";
            }
            else
            {
                library.Swap(i1, i2);
                cout << "\nBooks swapped.\n";
            }
            break;
        }
        case 7:
            library.Sort();
            cout << "\nBooks sorted by ID in ascending order.\n";
            break;
        case 8:
            library.Reverse();
            cout << "\nBook collection reversed.\n";
            break;
        case 9:
        {
            if (library.IsEmpty())
                cout << "\nStatus: The collection is EMPTY.\n";
            else
                cout << "\nStatus: The collection is NOT empty. "
                     << "Total books: " << library.GetCount() << "\n";
            break;
        }
        case 10:
            cout << "\nExiting the Library System. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Please enter 1-10.\n";
        }

    } while (choice != 10);

    return 0;
}