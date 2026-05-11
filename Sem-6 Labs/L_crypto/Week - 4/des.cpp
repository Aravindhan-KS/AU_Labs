#include <iostream>
#include <cstring>
#include <openssl/des.h>
using namespace std;

int main() {
    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock encrypted;
    char plaintext[9], decrypted[9];
    
    cout << "Enter Plaintext (8 chars): ";
    cin >> plaintext;
    cout << "Enter Key (8 chars): ";
    cin >> key;

    DES_set_key_unchecked(&key, &schedule);
    DES_ecb_encrypt((DES_cblock*)plaintext, &encrypted, &schedule, DES_ENCRYPT);
    DES_ecb_encrypt(&encrypted, (DES_cblock*)decrypted, &schedule, DES_DECRYPT);

    decrypted[8] = '\0';

    cout << "\nEncrypted Text (Hex): ";
    for (int i = 0; i < 8; i++)
    {
        printf("%02X", encrypted[i]);
    }
    cout << "\nDecrypted Text: " << decrypted << endl;
    return 0;
}