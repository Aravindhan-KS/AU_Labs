#include <iostream>
#include <openssl/aes.h>
#include <cstring>
using namespace std;

int main() {
    unsigned char plaintext[16];
    unsigned char encrypted[16];
    unsigned char decrypted[16];
    unsigned char key[32];
    int keySize;
    AES_KEY enc_key, dec_key;
    
    cout << "Enter Plaintext (16 chars): ";
    cin >> plaintext;
    cout << "Enter Key Size (128/192/256): ";
    cin >> keySize;
    cout << "Enter Key: ";
    cin >> key;

    AES_set_encrypt_key(key, keySize, &enc_key);
    AES_encrypt(plaintext, encrypted, &enc_key);
    AES_set_decrypt_key(key, keySize, &dec_key);
    AES_decrypt(encrypted, decrypted, &dec_key);

    cout << "\nEncrypted Text (Hex): ";
    for (int i = 0; i < 16; i++)
    {
        printf("%02X", encrypted[i]);
    }
    cout << "\nDecrypted Text: " << decrypted << endl;
    return 0;
}