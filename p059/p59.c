#include <stdio.h>
#include <string.h>

void decrypt(int encrypted[1201], char plaintext[1202]) {
    for(char a = 97; a <= 122; a++) {
    for(char b = 97; b <= 122; b++) {
    for(char c = 97; c <= 122; c++) {
        memset(plaintext, '\0', 1202);
        char key[3] = { a, b, c };

        for(int i = 0; i < 1201; i++) {
            plaintext[i] = (char)(encrypted[i] ^ key[i % 3]);
        }

        if(strstr(plaintext, " the ") != NULL) {
            return;
        }
    }
    }
    }
}

int main(int agc, char* argv[]) {

    // there are 1201 items in cipher1.txt
    int encrypted[1201] = { '\0' };
    int* eptr = encrypted;
    char plaintext[1202] = { '\0' };

    FILE* hFile = fopen("cipher1.txt", "r");

    while(fscanf(hFile, "%i,", eptr) != EOF) {
        eptr++;
    }

    decrypt(encrypted, plaintext);

    int sum = 0;
    for(int i = 0; i < 1201; i++) {
        sum += plaintext[i];
    }

    printf("%i", sum);

    return 0;
}

