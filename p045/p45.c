#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long u64;

u64 triangle(u64 n) {
    return n * (n + 1) / 2;
}

u64 pentagon(u64 n) {
    return n * (3 * n - 1) / 2;
}

u64 hexagon(u64 n) {
    return n * (2 * n - 1);
}

int main(int argc, char* argv[]) {

    int t = 286;
    int p = 165;
    int h = 143;

    u64 tval = triangle(t);
    u64 pval = pentagon(p);
    u64 hval = hexagon(h);

    bool found = false;

    while(!found) {
        while(hval < pval) {
            h++;
            hval = hexagon(h);
        }

        while(pval < tval) {
            p++;
            pval = pentagon(p);
        }

        if(tval == pval && tval == hval) {
            found = true;
        } else {
            t++;
            tval = triangle(t);
        }
    }

    printf("%llu", tval);

    return 0;
}

