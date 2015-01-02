#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool same(char* s1, char* s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    if(s1len != s2len) return false;

    for(int i = 0; i < s1len; i++) {
        int count = 0;
        for(int j = 0; j < s1len; j++) {
            if(s1[i] == s2[j]) count++;
        }
        if(count != 1) return false;
    }
    return true;
}


int main(int argc, char* argv[]) {

    for(int i = 102; ; i++) {
        char s1[64] = { '\0' };
        sprintf(s1, "%i", i);
        if(s1[0] != '1') continue;

        bool found = true;
        for(int x = 2; x <= 6; x++) {
            char s2[64] = { '\0' };
            sprintf(s2, "%i", i * x);
            if(!same(s1, s2)) {
                found = false;
                break;
            }
        }

        if(found) {
            printf("%i", i);
            break;
        }
    }

    return 0;
}

