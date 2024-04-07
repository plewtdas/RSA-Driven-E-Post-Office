#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

// Function declarations for user interface
void displayMainMenu();
void registerUserInterface();
void loginUserInterface();
void sendMessageInterface();
void receiveMessagesInterface();

// Function to retrieve the username of the currently logged-in user
std::string getCurrentUser();

#endif // INTERFACE_H
