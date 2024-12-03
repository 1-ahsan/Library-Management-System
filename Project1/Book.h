#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    int publicationYear;
    bool isAvailable;

public:
    // Constructor
    Book();
    Book(string title, string author, string ISBN, int publicationYear);

    // Getters
    string getTitle();
    string getAuthor();
    string getISBN();
    int getPublicationYear() const;
    bool getAvailability() const;

    // Setters
    void setTitle(string t);
    void setAuthor(string a);
    void setISBN(string i);
    void setPublicationYear(int pYear);
    void setAvailability(bool available);

    // member functions
    void borrow() {
        this->isAvailable = false;
        cout << "Done" << endl;
    }
    void returnBook() {
        this->isAvailable = true;
        cout << "Done" << endl;
    }


    // Operator overloading
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;
    friend ostream& operator<<(ostream& os, const Book& book);
};