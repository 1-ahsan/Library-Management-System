#include <iostream>
#include <string>
#include "Student.h"

using namespace std;


Request::Request() {
    this->title = "";
    this->studentID = "";
    this->status = "Pending";
}
Request::Request(string Title, string studentID) {
    this->title = Title;
    this->studentID = studentID;
    this->status = "Pending";
}


// Constructor
Student::Student() {
    this->userID = "";
    this->name = "";
    this->password = "";
    this->course = "";
    this->year = 0;
    this->borrowed = new CircularQueue<Book>(3);  // a student can only borrow 4 books at a time
    this->history = new CircularQueue<Book>(5);    // can store history fo only 5 books
    this->requests =new LinkedList<Request>();
}
Student::Student(string id, string n, string c, int y, string key) : User(id, n, key), course(c), year(y) {
    this->borrowed = new CircularQueue<Book>(3);  // a student can only borrow 4 books at a time
    this->history = new CircularQueue<Book>(5);    // can store history fo only 5 books
    this->requests =new LinkedList<Request>();
}

void Student::displayDetails() {
    User::displayDetails();
    cout << "Course: " << course << endl;
    cout << "Year: " << year << endl;
}

// Overloading the == operator
bool Student::operator==(const Student& other) const {
    return (userID==other.userID &&
        name == other.name);
}
bool Student::operator!=(const Student& other) const {
    return !(*this == other);
}

// borrowing scheme
void Student::generateBorrowRequest(string bookTitle) {
    Request r(bookTitle, this->getUserID());
    requests->append(r);
}
void Student::printRequests() {
    int size = requests->getSize();
    Node<Request>* temp = requests->peak();
    while (size) {
        cout << "Books Title: \n";
        cout << temp->data.title << endl;
        cout << temp->data.status << endl;
        size--;
        temp = temp->next;
    }
}
LinkedList<Request>* Student::getRequests() {
    return (requests);
}
