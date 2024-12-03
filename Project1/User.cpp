#include <iostream>
#include <string>
#include "User.h"

using namespace std; 


    // Constructor
User::User() {
    this->userID = "";
    this->name = "";
    this->password = "";
}
User::User(string id, string n, string key) : userID(id), name(n), password(key) {}

// Virtual Function to Display User Details
 void User::displayDetails() {
    cout << "User ID: " << userID << endl;
    cout << "Name: " << name << endl;
}

string User::getUserID() { return userID; }
string User::getUserName() { return name; }

bool User::login(string id, string key) {
    if (((!(this->userID.compare(id))) && (!(this->password.compare(key))))) {
        cout << "Loging in......" << endl;
        return true;
    }
    cout << "Wrong input" << endl;
    return false;
}
