#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5000

int pents[MAX] = { 0 };

int pentagon(int n) {
    return n * (3 * n - 1) / 2;
}

// need to use hashmap for speedup, but uses much more memory
bool exists(int n) {
    bool exists = false;
    for(int i = 1; i < MAX; i++) {
        if(pents[i] == n) {
            exists = true;
            break;
        }
    }
    return exists;
}

int main(int argc, char* argv[]) {

    for(int i = 1; i < 5000; i++) {
        int p = pentagon(i);
        pents[i] = p;
    }

    for(int i = 1; ; i++) {
        int ip = pents[i];
    for(int j = 1; j <= i; j++) {
        int jp = pents[j];

        int add = ip + jp;
        int diff = abs(jp - ip);

        if(!exists(add)) continue;
        if(!exists(diff)) continue;

        printf("%i", abs(jp - ip));
        return 0;
    }
    }
    return 0;
}

