#include <iostream>
#include <openssl/des.h>
#include <cstring>
#include <iomanip>

using namespace std;

void printHex(const unsigned char* data, int len) {
    for (int i = 0; i < len; i++)
        cout << hex << setw(2) << setfill('0') << (int)data[i];
    cout << dec << endl;
}

int main() {
    string plaintext, keystr;

    cout << "Enter plaintext (max 8 characters): ";
    cin >> plaintext;
    cout << "Enter key (8 characters): ";
    cin >> keystr;

    if (keystr.length() != 8) {
        cout << "Error: DES key must be exactly 8 characters.\n";
        return 1;
    }

    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock iv = {0};
    
    memcpy(key, keystr.c_str(), 8);
    DES_set_key_unchecked(&key, &schedule);
    int num = 0;
    unsigned char encrypted[8];
    unsigned char decrypted[8];

    DES_ofb64_encrypt(
        (unsigned char*)plaintext.c_str(),
        encrypted,
        plaintext.length(),
        &schedule,
        &iv,
        &num
    );

    cout << "\nEncrypted Text (Hex): ";
    printHex(encrypted, plaintext.length());
    memset(iv, 0, sizeof(iv));
    num = 0;

    DES_ofb64_encrypt(
        encrypted,
        decrypted,
        plaintext.length(),
        &schedule,
        &iv,
        &num
    );

    cout << "Decrypted Text: ";
    for (int i = 0; i < plaintext.length(); i++)
        cout << decrypted[i];
    cout << endl;

    return 0;
}