#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <utility>
using namespace std;

// ========================================
// Book Node
// ========================================
struct BookNode
{
    int bookID;
    string title;
    BookNode* next;
};

// ========================================
// Linked List Class
// ========================================
class LinkedList
{
private:
    BookNode* head;
    int count;

    // Return the node at a valid index
    BookNode* GetNodeAt(int index)
    {
        BookNode* current = head;
        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;
        return current;
    }

    // Swap book data between two nodes
    void CopyBookData(BookNode* a, BookNode* b)
    {
        swap(a->bookID, b->bookID);
        swap(a->title, b->title);
    }

public:
    LinkedList()
    {
        head = nullptr;
        count = 0;
    }

    // Insert a book at the head
    void Insert(BookNode* book)
    {
        if (book == nullptr)
            return;
        book->next = head;
        head = book;
        count++;
    }

    // Remove a book from the head
    BookNode* Remove()
    {
        if (IsEmpty())
            return nullptr;
        BookNode* book = head;
        head = head->next;
        book->next = nullptr;
        count--;
        return book;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    bool IsNotEmpty()
    {
        return head != nullptr;
    }

    int GetCount()
    {
        return count;
    }

    // Insert at a specified index
    void InsertAt(BookNode* book, int index)
    {
        if (book == nullptr)
            return;

        if (index < 0)
            index = 0;
        if (index > count)
            index = count;

        if (index == 0)
        {
            Insert(book);
            return;
        }

        BookNode* previous = GetNodeAt(index - 1);
        book->next = previous->next;
        previous->next = book;
        count++;
    }

    // Remove at a specified index
    BookNode* RemoveAt(int index)
    {
        if (IsEmpty())
            return nullptr;

        if (index < 0)
            index = 0;
        if (index >= count)
            index = count - 1;

        if (index == 0)
            return Remove();

        BookNode* previous = GetNodeAt(index - 1);
        BookNode* book = previous->next;
        previous->next = book->next;
        book->next = nullptr;
        count--;
        return book;
    }

    // Swap book data at two indexes
    void Swap(int index1, int index2)
    {
        if (index1 < 0 || index1 >= count ||
            index2 < 0 || index2 >= count)
            return;

        if (index1 == index2)
            return;

        BookNode* first = GetNodeAt(index1);
        BookNode* second = GetNodeAt(index2);
        CopyBookData(first, second);
    }

    // Sort books by book ID in ascending order
    void Sort()
    {
        for (BookNode* i = head; i != nullptr; i = i->next)
        {
            for (BookNode* j = i->next; j != nullptr; j = j->next)
            {
                if (i->bookID > j->bookID)
                    CopyBookData(i, j);
            }
        }
    }

    // Reverse the linked list
    void Reverse()
    {
        BookNode* previous = nullptr;
        BookNode* current = head;
        BookNode* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    // Display all books
    void Print()
    {
        BookNode* current = head;
        int index = 0;

        cout << "\nIndex\tBook ID\tTitle\n";
        cout << "-----------------------------------\n";
        while (current != nullptr)
        {
            cout << index << "\t"
                 << current->bookID << "\t"
                 << current->title << endl;
            current = current->next;
            index++;
        }
        cout << "Total books: " << count << endl;
    }

    // Copy constructor: create independent nodes
    LinkedList(const LinkedList& other)
    {
        head = nullptr;
        count = 0;

        BookNode* current = other.head;
        while (current != nullptr)
        {
            BookNode* copy = new BookNode{ current->bookID, current->title, nullptr };
            InsertAt(copy, count);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other)
    {
        if (this == &other)
            return *this;

        while (!IsEmpty())
            delete Remove();

        BookNode* current = other.head;
        while (current != nullptr)
        {
            BookNode* copy = new BookNode{ current->bookID, current->title, nullptr };
            InsertAt(copy, count);
            current = current->next;
        }
        return *this;
    }

    // Destructor
    ~LinkedList()
    {
        while (!IsEmpty())
            delete Remove();
    }
};

// ========================================
// Create a Book Node
// ========================================
inline BookNode* CreateBook(int id, string title)
{
    BookNode* book = new BookNode;
    book->bookID = id;
    book->title = title;
    book->next = nullptr;
    return book;
}

#endif