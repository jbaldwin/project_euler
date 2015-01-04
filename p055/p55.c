#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/int128.h"

typedef unsigned __int128 u128;

u128 reverse(u128 n) {
    u128 r = 0;
    while(n != 0) {
        r = r * 10;
        r = r + n % 10;
        n /= 10;
    }
    return r;
}

bool is_palindrome(u128 n) {
    return n == reverse(n);
}

int main(int argc, char* argv[]) {
    int lychrelCount = 0;

    for(u128 i = 10; i < 10000; i++) {
        int iterations = 0;
        u128 next = i;

        do {
            next = next + reverse(next);
            iterations++;
        } while(!is_palindrome(next) && iterations < 50);

        if(iterations >= 50) lychrelCount++;
    }

    printf("%i", lychrelCount);

    return 0;
}

