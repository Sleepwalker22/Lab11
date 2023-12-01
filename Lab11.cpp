#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Library
{
public:
    // constructor
    // creates a library with no books
    Library();

    // Adds the given book to the library and returns zero
    // returns false if the book already exists or if the library
    //   already has 10 books
    bool addBook(string bookName);

    // Removes the given book name from the library by setting the
    //   corresponding string to "", and returns true
    // returns false if the library does not have the given book
    bool removeBook(string bookName);

    // prints the book names
    void print();

private:
    string books[10]; // book names. (by default, all are initialized with "")
};

// implement class functions
Library::Library()
{
    for (int i = 0; i < 10; i++)
    {
        books[i] = "";
    }
}
bool Library::addBook(string bookName)
{
    for (int i = 0; i < 10; i++)
    {
        if (books[i] == "")
        {
            books[i] = bookName;
            return true;
        }
        else if (books[i] == bookName)
        {
            return false;
        }
    }
    return false;
}

bool Library::removeBook(string bookName)
{
    for (int i = 0; i < 10; i++)
    {
        if (books[i] == bookName)
        {
            books[i] = "";
            return true;
        }
    }
    return false;
}
void Library::print()
{
    cout << "Library contents:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (books[i] != "")
        {
            cout << books[i] << endl;
        }
    }
}

int main()
{
    Library library;
    char command = 'z';
    string bookName;
    while (command != 'q')
    {
        cout << "Enter command: ";
        cin >> command;
        if (command == 'a')
        {
            cin >> bookName;
            bool check = library.addBook(bookName);
        }
        if (command == 'r')
        {
            cin >> bookName;
            bool check = library.removeBook(bookName);
        }
        if (command == 'p')
        {
            library.print();
        }
    }
    cout << "Exiting" << endl;
    return 0;
    // ask for commands and execute
}
