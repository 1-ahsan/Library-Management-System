#include <iostream>
#include <string>

#include "Administrator.h"
#include "Book.h"
#include "Data Structure.h"
#include "Student.h"

using namespace std;

Administrator admin1("123", "Ahsan", "Head", "ah12");
Administrator admin2("124", "Rohail", "Head2", "ga12");

void UserLogin() {
    string id, key;
    cout << "Enter your Id: ";
    getline(cin, id);
    cout << "Enter your password : ";
    getline(cin, key);
    LinkedList<Student>* students= admin1.getStudents();
    Node<Student>* stu=students->peak();
    while (stu) {
        if (stu->data.login(id, key)) {
            //
            return;
        }
    }
    cout << "Something went wrong" << endl;
    return;
}

void AdminLogin() {
    cout << "Enter your Id: ";
    string id, password;
    getline(cin, id);
    cout << "Enter your password : ";
    getline(cin, password);
    if (admin1.login(id, password) || admin2.login(id, password)) {
        cout << "hello" << endl;
    }
    else {
        cout << "Sorry! something is wrong" << endl;
    }
    return;
}

void WelcomePage() {
    cout << "Your options: " << endl;
    cout << "1. for User Lgin" << endl;
    cout << "2. for Admin Login" << endl;
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
        UserLogin();
        break;
    case 2:
        AdminLogin();
        break;
    }
}

void menuforadmin() {
    int num;
    cout << "Enter your choice to perform action: " << endl;
    cout << "Enter 1 to Display books" << endl;
    cout << "Enter 2 to Add book" << endl;
    cout << "Enter 3 to Delete book" << endl;
    cout << "Enter 4 to Add user" << endl;
    cout << "Enter 5 to Delete user" << endl;
    cout << "Enter 6 to Update user" << endl;
    cin >> num;
    cin.ignore();
    switch (num) {
    case 1:
        cout << "Displaying books..." << endl;
        admin1.printBooks();
        break;
    case 2:
        cout << "Adding a new book..." << endl;

        admin1.addBooks();
        break;
    case 3:
        cout << "Deleting a book..." << endl;
        admin1.deleteBooks();
        break;
    case 4:
        cout << "Adding a new user..." << endl;
        admin1.addUser();
        break;
    case 5:
        cout << "Deleting a user..." << endl;
        admin1.addUser();
        break;

    case 6:
        cout << "Searching a User..." << endl;
        admin1.searchUser();
        break;
    case 7:
        cout << "Printing Users..." << endl;
        admin1.printUsers();
        break;

    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}
void menuforuser() {
    int choice;
    cout << "Enter your choice: " << endl;
    cout << "Enter 1 to View issued book" << endl;
    cout << "Enter 2 to Issue a book" << endl;
    cout << "Enter 3 to Update book record" << endl;
    cout << "Enter 4 to Delete issued book" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Viewing issued book..." << endl;
        break;
    case 2:
        cout << "Issuing a book..." << endl;
        break;
    case 3:
        cout << "Updating book record..." << endl;
        break;
    case 4:
        cout << "Deleting issued book..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

int main() {

    WelcomePage();
    
    return 0;
}