#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5000
// Bucket size of two appears to have zero collisions
#define BUCKET_SIZE 2

int pents[MAX] = { 0 };
int pents_rev[MAX][BUCKET_SIZE] = { { 0 } };

int pentagon(int n) {
    return n * (3 * n - 1) / 2;
}

int hash(int n) {
    return (n * 7) % 5000;
}

bool exists(int n) {
    bool exists = false;
    int h = hash(n);
    for(int i = 0; i < BUCKET_SIZE; i++) {
        if(pents_rev[h][i] == 0) {
            break;
        } else if(pents_rev[h][i] == n) {
            exists = true;
            break;
        }
    }
    return exists;
}

bool insert(int n) {
    int h = hash(n);
    bool inserted = false;
    for(int i = 0; i < BUCKET_SIZE; i++) {
        if(pents_rev[h][i] == 0) {
            pents_rev[h][i] = n;
            inserted = true;
            break;
        }
    }
    return inserted;
}


int main(int argc, char* argv[]) {

    // Create an array of all known pentagrams up to n = 5000
    // Create a revershed hash map of all pentagrams mapped into
    // a hashmap of 5000 buckets with max collision of 2
    for(int i = 1; i < 5000; i++) {
        int p = pentagon(i);
        pents[i] = p;
        insert(p);
    }

    for(int i = 1; ; i++) {
        int ip = pents[i];
    for(int j = 1; j <= i; j++) {
        int jp = pents[j];

        int add = ip + jp;
        if(!exists(add)) continue;
        int diff = abs(jp - ip);
        if(!exists(diff)) continue;

        printf("%i", abs(jp - ip));
        return 0;
    }
    }
    return 0;
}

