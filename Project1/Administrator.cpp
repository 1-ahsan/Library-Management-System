#include <iostream>
#include <string>
#include "Administrator.h"

using namespace std;


// Constructor
Administrator::Administrator(string id, string n, string role, string key) : User(id, n, key), adminRole(role) {}

LinkedList<Book> Administrator::books;
LinkedList<Student> Administrator::students;

LinkedList<Student>* Administrator::getStudents() {
    return &students;
}
void Administrator::displayDetails() {
    cout << "Administrator Details:" << endl;
    User::displayDetails();
    cout << "Role: " << adminRole << endl;
}
void Administrator::addBooks() {
    string title, auther, id;
    int pulisher;
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Auther: ";
    getline(cin, auther);
    cout << "Enter ISBN : ";
    getline(cin, id);
    cout << "Enter publisher year : ";
    cin >> pulisher;
    cin.ignore();
    Book b(title, auther, id, pulisher);
    this->books.append(b);
}
void Administrator::deleteBooks() {
    string title, auther, id;
    int pulisher;
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Auther: ";
    getline(cin, auther);
    cout << "Enter ISBN : ";
    getline(cin, id);
    cout << "Enter publisher year : ";
    cin >> pulisher;
    cin.ignore();
    Book b(title, auther, id, pulisher);
    this->books.remove(b);
}
 void Administrator::printBooks() {
     books.display();
}
 void Administrator::searchBook(string title) {
     Node<Book>* temp = books.peak();
     int size = books.getSize();
     while (size) {
         if (!(temp->data.getTitle().compare(title))) {
             cout << (temp->data) << endl;
             return;
         }
         temp = temp->next;
         size--;
     }
     cout << "Not found" << endl;
 }


 // User management
 void Administrator::addUser() {
     string id, name, course, key;
     cout << "Enter user ID: ";
     getline(cin, id);
     cout << "Enter name: ";
     getline(cin, name);
     cout << "Enter course: ";
     getline(cin, course);
     cout << "Enter password";
     getline(cin, key);
     int year;
     cout << "Enter year: ";
     cin >> year;
     cin.ignore();
     Student s(id, name, course,year, key);
     students.append(s);
 }
 void Administrator::removeUser() {
     string id, name, course, key;
     cout << "Enter user ID: ";
     getline(cin, id);
     cout << "Enter name: ";
     getline(cin, name);
     cout << "Enter course: ";
     getline(cin, course);
     cout << "Enter password";
     getline(cin, key);
     int year;
     cout << "Enter year: ";
     cin >> year;
     cin.ignore();
     Student s(id, name, course, year, key);
     students.remove(s);
 }
 Student Administrator::searchUser() {
     string name;
     cout << "Enter name: ";
     getline(cin, name);
     int size = students.getSize();
     Node<Student>* temp = students.peak();
     while (size) {
         if (!(temp->data.getUserName().compare(name))) {
             temp->data.displayDetails();
             return temp->data;
         }
         size--;
     }
     cout << "not found" << endl;
 }
 void Administrator::printUsers() {
     Node<Student>* s = students.peak();
     while (s) {
         s->data.displayDetails();
         s = s->next;
     }
 }


 void Administrator::PrintRequest() {
     int size = students.getSize();
     Node<Student>* st = students.peak();
     while (size) {
         LinkedList<Request>* r = st->data.getRequests();
         int s2 = r->getSize();
         Node<Request>* r2 = r->peak();
         if (s2 > 0)
             cout << "Requests by: " << st->data.getUserID() << " : " << endl;
         while (s2) {
             cout << r2->data.title << "\t";
             r2 = r2->next;
             s2--;
         }
         cout << endl;
         st = st->next;
         size--;
     }
 }
 void Administrator::approveRequest(string id,string title) {
     int size = students.getSize();
     Node<Student>* st = students.peak();
     while (size) {
         if (!(st->data.getUserID().compare(id))) {
             LinkedList<Request>* req = st->data.getRequests();
             size = req->getSize();
             Node<Request>* temp = req->peak();
             while (size) {
                 if (!(temp->data.title.compare(title))) {
                     temp->data.status = "Approved";
                     break;
                 }
                 size--;
             }
         }
         st = st->next;
         size--;
     }
     
 }
 void Administrator::giveBook(string id) {
     int size = books.getSize();
     Node<Book>* temp = books.peak();
     while (size) {
         if (!(temp->data.getISBN().compare(id))) {
             temp->data.borrow();
             return;
         }
     }
     cout << "Record not found" << endl;
 }
 void Administrator::returnBook(string id) {
     int size = books.getSize();
     Node<Book>* temp = books.peak();
     while (size) {
         if (!(temp->data.getISBN().compare(id))) {
             temp->data.returnBook();
             return;
         }
     }
     cout << "Record not found" << endl;
 }

