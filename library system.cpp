#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int bookID;
    string title, author, genre;
    bool isIssued;
    Book *prev, *next;

    Book(int id, string t, string a, string g) {
        bookID = id;
        title = t;
        author = a;
        genre = g;
        isIssued = false;
        prev = next = NULL;
    }
};

class Library {
private:
    Book* head;

public:
    Library() {
        head = NULL;
    }

    // Add book at end
    void addBook() {
        int id;
        string title, author, genre;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Genre: ";
        getline(cin, genre);

        Book* newBook = new Book(id, title, author, genre);

        if (head == NULL) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newBook;
            newBook->prev = temp;
        }

        cout << "\n Book Added Successfully!\n";
    }

    // Display all books
    void displayBooks() {
        if (head == NULL) {
            cout << "\nNo Books Available.\n";
            return;
        }

        Book* temp = head;
        cout << "\n------ Library Books ------\n";
        while (temp != NULL) {
            cout << "Book ID: " << temp->bookID << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Genre: " << temp->genre << endl;
            cout << "Status: " << (temp->isIssued ? "Issued" : "Available") << endl;
            cout << "--------------------------\n";
            temp = temp->next;
        }
    }

    // Search Book by ID
    Book* searchBook(int id) {
        Book* temp = head;
        while (temp != NULL) {
            if (temp->bookID == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Issue Book
    void issueBook() {
        int id;
        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        Book* book = searchBook(id);

        if (book == NULL) {
            cout << " Book Not Found!\n";
        } else if (book->isIssued) {
            cout << " Book Already Issued!\n";
        } else {
            book->isIssued = true;
            cout << " Book Issued Successfully!\n";
        }
    }

    // Return Book
    void returnBook() {
        int id;
        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        Book* book = searchBook(id);

        if (book == NULL) {
            cout << " Book Not Found!\n";
        } else if (!book->isIssued) {
            cout << "Book is Not Issued!\n";
        } else {
            book->isIssued = false;
            cout << " Book Returned Successfully!\n";
        }
    }

    // Delete Book
    void deleteBook() {
        int id;
        cout << "\nEnter Book ID to Delete: ";
        cin >> id;

        Book* book = searchBook(id);

        if (book == NULL) {
            cout << " Book Not Found!\n";
            return;
        }

        if (book->prev != NULL)
            book->prev->next = book->next;

        if (book->next != NULL)
            book->next->prev = book->prev;

        if (book == head)
            head = book->next;

        delete book;
        cout << " Book Deleted Successfully!\n";
    }

    void countBooks() {
        int count = 0;
        Book* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "\nTotal Books in Library: " << count << endl;
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=========== Library Management System ===========";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Delete Book";
        cout << "\n6. Count Books";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.deleteBook(); break;
            case 6: lib.countBooks(); break;
            case 7: cout << "\nExiting Program...\n"; break;
            default: cout << "\n Invalid Choice! Try Again.\n";
        }
    } while (choice != 7);

    return 0;
}

