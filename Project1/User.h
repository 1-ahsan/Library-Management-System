#pragma once
#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    string userID;
    string name;
    string password;

public:
    // Constructor
    User();
    User(string id, string n, string key);

    // Virtual Function to Display User Details
    virtual void displayDetails();

    string getUserID();
    string getUserName();

    bool login(string id, string key);
};
