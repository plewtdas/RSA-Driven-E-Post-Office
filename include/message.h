#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

// Define a structure to represent a message
struct Message {
    string sender;
    string recipient;
    string content;
};

// Function declarations for message handling
bool sendMessage(const string& sender, const string& recipient, const string& content);
bool receiveMessages(const string& recipient);

#endif // MESSAGE_H
