#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Data Structure.h"
#include "Book.h"

using namespace std;

class Request {
public:
    string title;
    string studentID;
    string status;

    Request();
    Request(string Title, string studentID);
};

class Student : public User {
private:
    string course;
    int year;
    CircularQueue<Book>* borrowed;   // for borrowed books
    CircularQueue<Book>* history;    // to store the history of last 10 books;
    LinkedList<Request>* requests;
public:
    // Constructor
    Student();
    Student(string id, string n, string c, int y, string key);

    void displayDetails() override;

    // Operator overloading
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;

    // borrowing scheme
    void generateBorrowRequest(string bookTitle);
    void printRequests();
    LinkedList<Request>* getRequests();
};

struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student s) {
        data = s;
        left = right = nullptr;
    }
};

