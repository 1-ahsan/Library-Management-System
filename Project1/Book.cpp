#include <iostream>
#include <string>
#include "Book.h"

using namespace std;


// Constructor
Book::Book() {
    this->title = "";
    this->author = "";
    this->ISBN = "";
    this->publicationYear = 0;
    isAvailable = true;
}
Book::Book(string title, string author, string ISBN, int publicationYear) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publicationYear = publicationYear;
    isAvailable = true; // Default: Book is available
}

// Getters
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return ISBN; }
int Book::getPublicationYear() const { return publicationYear; }
bool Book::getAvailability() const { return isAvailable; }

// Setters
void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setISBN(string i) { ISBN = i; }
void Book::setPublicationYear(int pYear) { publicationYear = pYear; }
void Book::setAvailability(bool available) { isAvailable = available; }


// Overloading the == operator
bool Book::operator==(const Book& other) const {
    return (ISBN == other.ISBN &&
        title == other.title &&
        author == other.author);
}
bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}
ostream& operator<<(ostream& os, const Book& book) {
    os << "Title: " << book.title << "\n"
        << "Author: " << book.author << "\n"
        << "ISBN: " << book.ISBN << "\n"
        << "Publication Year: " << book.publicationYear << "\n"
        << "Availability: " << (book.isAvailable ? "Available" : "Not Available");
    return os;
}