#include "user.h"
#include <iostream>
#include <fstream>

using namespace std;


bool registerUser(const string& username, const string& password) {
    // Open a file to store user credentials 
    ofstream userFile("users.txt", ios::app);
    
    // Check if the file was opened successfully
    if (!userFile) {
        cerr << "Server Error: Unable to open user database file." << endl;
        return false;
    }
    
    // Check if the username is already taken
    ifstream checkFile("users.txt");
    string line;
    while (getline(checkFile, line)) {
        size_t pos = line.find(':');
        if (line.substr(0, pos) == username) {
            cerr << "Error: Username already exists." << endl;
            return false;
        }
    }
    
    // Write the new user's credentials to the file
    userFile << username << ":" << password << endl;
    userFile.close();
    cout << "User registered successfully." << endl;
    return true;
}

// Function to authenticate user login
bool loginUser(const string& username, const string& password) {
    // Open the user database file
    ifstream userFile("users.txt");
    
    // Check if the file was opened successfully
    if (!userFile) {
        cerr << "Server Error: Unable to open user database file." << endl;
        return false;
    }

    // Check if the username and password match
    string line;
    while (getline(userFile, line)) {
        size_t pos = line.find(':');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);
        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful. Welcome, " << username << "!" << endl;
            userFile.close();
            return true;
        }
    }
    
    cerr << "Error: Incorrect username or password. Try Again" << endl;
    userFile.close();
    return false;
}
