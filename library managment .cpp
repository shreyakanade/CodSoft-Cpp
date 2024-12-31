#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

// Function to add a new book to the library
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

// Function to display all books in the library
void displayBooks(const vector<Book>& books) {
    cout << "Library Catalog:" << endl;
    for (const Book& book : books) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.isbn << endl;
        cout << "Availability: " << (book.isAvailable ? "Available" : "Not Available") << endl;
        cout << "--------------------" << endl;
    }
}

// Function to search for a book by title
void searchBook(const vector<Book>& books) {
    string title;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, title);
    bool found = false;
    for (const Book& book : books) {
        if (book.title == title) {
            cout << "Book Found:" << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "Availability: " << (book.isAvailable ? "Available" : "Not Available") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to issue a book to a borrower
void issueBook(vector<Book>& books) {
    string isbn;
    cout << "Enter ISBN of the book to issue: ";
    getline(cin, isbn);
    bool found = false;
    for (Book& book : books) {
        if (book.isbn == isbn && book.isAvailable) {
            book.isAvailable = false;
            cout << "Book issued successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found or not available." << endl;
    }
}

// Function to return a book to the library
void returnBook(vector<Book>& books) {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    getline(cin, isbn);
    bool found = false;
    for (Book& book : books) {
        if (book.isbn == isbn) {
            book.isAvailable = true;
            cout << "Book returned successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to save book data to a file
void saveBooksToFile(const vector<Book>& books, const string& filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const Book& book : books) {
            outfile << book.title << endl;
            outfile << book.author << endl;
            outfile << book.isbn << endl;
            outfile << book.isAvailable << endl;
        }
        outfile.close();
        cout << "Book data saved to " << filename << endl;
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

// Function to load book data from a file
void loadBooksFromFile(vector<Book>& books, const string& filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            Book book;
            book.title = line;
            getline(infile, book.author);
            getline(infile, book.isbn);
            infile >> book.isAvailable;
            infile.ignore(); // Ignore newline character
            books.push_back(book);
        }
        infile.close();
        cout << "Book data loaded from " << filename << endl;
    } else {
        cout << "Error: Unable to open file for reading." << endl;
    }
}

int main() {
    vector<Book> library;
    string filename = "library.txt"; // File to store book data

    // Load book data from file (if exists)
    loadBooksFromFile(library, filename);

    int choice;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                issueBook(library);
                break;
            case 5:
                returnBook(library);
                break;
            case 6:
                saveBooksToFile(library, filename);
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}
