#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string username;
    std::string password;
};


bool registerUser(const std::string& username, const std::string& password);
bool loginUser(const std::string& username, const std::string& password);

#endif // USER_H
