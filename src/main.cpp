#include "interface.h"
#include <iostream>

using namespace std;

int main() {
    int choice;
    do {
        // Display main menu
        displayMainMenu();

        // Prompt user for choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                registerUserInterface();
                break;
            case 2:
                loginUserInterface();
                break;
            case 3:
                sendMessageInterface();
                break;
            case 4:
                receiveMessagesInterface();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
