#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;

public:
    Book(string _title, string _author) : title(_title), author(_author), available(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        cout << "Library Books:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
        }
    }

    void searchByTitle(const string& title) const {
        cout << "Search Results for Title '" << title << "':" << endl;
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                found = true;
                cout << "Author: " << book.getAuthor() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
            }
        }
        if (!found) {
            cout << "No matching books found." << endl;
        }
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && book.isAvailable()) {
                book.borrowBook();
                cout << "You have borrowed the book: " << title << endl;
                return;
            }
        }
        cout << "Book not found or not available for borrowing." << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && !book.isAvailable()) {
                book.returnBook();
                cout << "You have returned the book: " << title << endl;
                return;
            }
        }
        cout << "Book not found or already returned." << endl;
    }
};

int main() {
    Library library;

    // Adding sample books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    library.addBook(Book("1984", "George Orwell"));

    // Display all books in the library
    library.displayAllBooks();

    // Borrowing a book
    library.borrowBook("The Great Gatsby");

    // Display all books after borrowing
    library.displayAllBooks();

    // Returning a book
    library.returnBook("The Great Gatsby");

    // Display all books after returning
    library.displayAllBooks();

    // Searching for a book by title
    library.searchByTitle("1984");

    return 0;
}
