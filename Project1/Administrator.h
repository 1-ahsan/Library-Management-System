#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Data Structure.h"
#include "Book.h"
#include "Student.h"

using namespace std;

class Administrator : public User {
private:
    string adminRole;
    static LinkedList<Book> books;
    static LinkedList<Student> students;
public:
    // Constructor
    Administrator(string id, string n, string role, string key);

    LinkedList<Student>* getStudents();
    void displayDetails() override;

    void addBooks();
    void deleteBooks();
    static void printBooks();
    static void searchBook(string Title);
    
    // user management
    void addUser();
    void removeUser();
    static Student searchUser();
    static void printUsers();

    // handling borrowing schemes
    void PrintRequest();
    void approveRequest(string id,string title);
    void giveBook(string ISBN);
    void returnBook(string ISBN);
};
