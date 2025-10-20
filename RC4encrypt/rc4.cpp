#include "rc4.h"
#include <algorithm>

RC4::RC4(const std::string& key) {
    S.resize(256);
    for (int i = 0; i < 256; i++)
        S[i] = i;
    KSA(key);
}

void RC4::KSA(const std::string& key) {
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key.length()]) % 256;
        std::swap(S[i], S[j]);
    }
}

unsigned char RC4::PRGA() {
    static int i = 0, j = 0;
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    std::swap(S[i], S[j]);
    return S[(S[i] + S[j]) % 256];
}

std::string RC4::encrypt(const std::string& plaintext) {
    std::string result = plaintext;
    for (size_t n = 0; n < plaintext.size(); n++) {
        result[n] = plaintext[n] ^ PRGA();
    }
    return result;
}

std::string RC4::decrypt(const std::string& ciphertext) {
    return encrypt(ciphertext); // RC4 giải mã giống mã hóa
}
