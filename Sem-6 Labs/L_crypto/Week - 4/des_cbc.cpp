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
        cerr << "Error: DES key must be exactly 8 characters.\n";
        return 1;
    }

    DES_cblock ivec; 
    DES_cblock iv;
    DES_cblock key;
    DES_key_schedule schedule;
    memcpy(key, keystr.c_str(), 8);
    DES_set_key_unchecked(&key, &schedule);
    memset(iv, 0, 8); 

    unsigned char input[8] = {0};
    unsigned char encrypted[8];
    unsigned char decrypted[8];
    memcpy(input, plaintext.c_str(), (plaintext.length() > 8) ? 8 : plaintext.length());

    memcpy(ivec, iv, 8);
    DES_ncbc_encrypt(input, encrypted, 8, &schedule, &ivec, DES_ENCRYPT);
    memcpy(ivec, iv, 8); 
    DES_ncbc_encrypt(encrypted, decrypted, 8, &schedule, &ivec, DES_DECRYPT);

    cout << "\nOriginal IV (Hex): ";
    printHex(iv, 8);
    cout << "Encrypted Text (Hex): ";
    printHex(encrypted, 8);

    cout << "Decrypted Text: ";
    for (int i = 0; i < 8; i++) {
        if (decrypted[i] >= 32) cout << decrypted[i];
    }
    cout << endl;
    return 0;
}