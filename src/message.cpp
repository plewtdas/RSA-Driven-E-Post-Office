#include "message.h"
#include <iostream>
#include <fstream>

using namespace std;

// Function to send a message
bool sendMessage(const string& sender, const string& recipient, const string& content) {
    // Open a file to store messages
    ofstream messageFile("messages.txt", ios::app);
    
    // Check if the file was opened successfully
    if (!messageFile) {
        cerr << "Error: Unable to open message database file." << endl;
        return false;
    }
    
    // Write the message to the file
    messageFile << "Sender: " << sender << endl;
    messageFile << "Recipient: " << recipient << endl;
    messageFile << "Content: " << content << endl;
    messageFile << "-------------------" << endl;
    
    messageFile.close();
    cout << "Message sent successfully." << endl;
    return true;
}

// Function to receive messages for a user
bool receiveMessages(const string& recipient) {
    // Open the message database file
    ifstream messageFile("messages.txt");
    
    // Check if the file was opened successfully
    if (!messageFile) {
        cerr << "Error: Unable to open message database file." << endl;
        return false;
    }
    
    string line;
    bool found = false;
    
    // Read messages from the file and display those intended for the recipient
    while (getline(messageFile, line)) {
        if (line.find("Recipient: " + recipient) != string::npos) {
            found = true;
            cout << line << endl;
            for (int i = 0; i < 3; ++i) {
                getline(messageFile, line); // Skip sender, recipient, and content lines
                cout << line << endl;
            }
            cout << "-------------------" << endl;
        }
    }
    
    messageFile.close();
    
    if (!found) {
        cout << "No messages found for " << recipient << "." << endl;
    }
    
    return true;
}
