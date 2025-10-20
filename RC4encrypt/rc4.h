#ifndef RC4_H
#define RC4_H

#include <string>
#include <vector>

class RC4 {
private:
    std::vector<unsigned char> S;
    void KSA(const std::string& key);
    unsigned char PRGA();
public:
    RC4(const std::string& key);
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);
};

#endif
