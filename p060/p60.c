#include <stdio.h>
#include <stdlib.h>

#include "../lib/prime.h"

int concat(int a, int b) {
    int p = 1;
    while(p < b) {
        p *= 10;
    }
    return a * p + b;
}

int main(int argc, char* argv[]) {

    int stop = 10000;

    for(int a = 3;     a < stop; a += 2) {
        if(!is_prime(a)) continue;

    for(int b = a + 2; b < stop; b += 2) {
        if(!is_prime(b)) continue;

        int ab = concat(a, b);
        if(!is_prime(ab)) continue;
        int ba = concat(b, a);
        if(!is_prime(ba)) continue;

    for(int c = b + 2; c < stop; c += 2) {
        if(!is_prime(c)) continue;

        int ac = concat(a, c);
        if(!is_prime(ac)) continue;
        int bc = concat(b, c);
        if(!is_prime(bc)) continue;
        int ca = concat(c, a);
        if(!is_prime(ca)) continue;
        int cb = concat(c, b);
        if(!is_prime(cb)) continue;

    for(int d = c + 2; d < stop; d += 2) {
        if(!is_prime(d)) continue;

        int ad = concat(a, d);
        if(!is_prime(ad)) continue;
        int bd = concat(b, d);
        if(!is_prime(bd)) continue;
        int cd = concat(c, d);
        if(!is_prime(cd)) continue;
        int da = concat(d, a);
        if(!is_prime(da)) continue;
        int db = concat(d, b);
        if(!is_prime(db)) continue;
        int dc = concat(d, c);
        if(!is_prime(dc)) continue;

    for(int e = d + 2; e < stop; e += 2) {
        if(!is_prime(e)) continue;

        int ae = concat(a, e);
        if(!is_prime(ae)) continue;
        int be = concat(b, e);
        if(!is_prime(be)) continue;
        int ce = concat(c, e);
        if(!is_prime(ce)) continue;
        int de = concat(d, e);
        if(!is_prime(de)) continue;
        int ea = concat(e, a);
        if(!is_prime(ea)) continue;
        int eb = concat(e, b);
        if(!is_prime(eb)) continue;
        int ec = concat(e, c);
        if(!is_prime(ec)) continue;
        int ed = concat(e, d);
        if(!is_prime(ed)) continue;

        printf("%i", a + b + c + d + e);
        exit(0);
    }
    }
    }
    }
    }

    return 0;
}

