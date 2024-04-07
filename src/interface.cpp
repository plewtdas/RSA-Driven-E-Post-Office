#include "interface.h"
#include "user.h"
#include "encryption.h"
#include "message.h"
#include <iostream>
#include <string>

using namespace std;

// Function to display the main menu
void displayMainMenu()
{
    cout << "Main Menu\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Send Message\n";
    cout << "4. Receive Messages\n";
    cout << "5. Exit\n";
}

// Function for user registration interface
void registerUserInterface()
{
    string username, password;
    cout << "User Registration\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    registerUser(username, password);
}

// Function for user login interface
void loginUserInterface()
{
    string username, password;
    cout << "User Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (loginUser(username, password))
    {
        sendMessageInterface();
    }
    else
    {
        cout << "Login failed. Please try again.\n";
    }
}

// Function for sending message interface
void sendMessageInterface()
{
    string recipient, message;
    cout << "Send Message\n";
    cout << "Enter recipient username: ";
    cin >> recipient;
    cout << "Enter message: ";
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, message);
    string encryptedMessage = rsaEncrypt(message);
    sendMessage(getCurrentUser(), recipient, encryptedMessage); // Pass the current user
}



// Function for receiving messages interface
void receiveMessagesInterface()
{
    cout << "Receive Messages\n";

    // Receive messages for the current user
    receiveMessages(getCurrentUser());
}

// Function to retrieve the username of the currently logged-in user
string getCurrentUser() {
    // Implement logic to retrieve the current user's username
    // For demonstration purposes, let's return a hardcoded username "current_user"
    return "not_displaying_the_sender_is_a_feature__and_not_a_bug_i_swear";
}
