#include <iostream>
#include "rc4.h"

int main() {
    std::string key = "HUST_KEY";
    std::string plaintext = "Hanoi University of Science and Technology";

    RC4 rc4(key);

    std::string ciphertext = rc4.encrypt(plaintext);
    std::cout << "Ciphertext (hex): ";
    for (unsigned char c : ciphertext)
        printf("%02X ", c);
    std::cout << std::endl;

    std::string decrypted = rc4.decrypt(ciphertext);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}


