#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

// To encrypt the message
std::string rsaEncrypt(const std::string& plaintext);
// To decrypt the message
std::string rsaDecrypt(const std::string& ciphertext);

#endif
