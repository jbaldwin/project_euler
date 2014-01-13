#include <stdio.h>
#include <stdlib.h>

#include "../lib/prime.c"

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
        int ba = concat(b, a);

        if(!is_prime(ab)) continue;
        if(!is_prime(ba)) continue;

    for(int c = b + 2; c < stop; c += 2) {
        if(!is_prime(c)) continue;

        int ac = concat(a, c);
        int bc = concat(b, c);
        int ca = concat(c, a);
        int cb = concat(c, b);

        if(!is_prime(ac)) continue;
        if(!is_prime(bc)) continue;
        if(!is_prime(ca)) continue;
        if(!is_prime(cb)) continue;

    for(int d = c + 2; d < stop; d += 2) {
        if(!is_prime(d)) continue;
    
        int ad = concat(a, d);
        int bd = concat(b, d);
        int cd = concat(c, d);
        int da = concat(d, a);
        int db = concat(d, b);
        int dc = concat(d, c);

        if(!is_prime(ad)) continue;
        if(!is_prime(bd)) continue;
        if(!is_prime(cd)) continue;
        if(!is_prime(da)) continue;
        if(!is_prime(db)) continue;
        if(!is_prime(dc)) continue;

    for(int e = d + 2; e < stop; e += 2) {
        if(!is_prime(e)) continue;

        int ae = concat(a, e);
        int be = concat(b, e);
        int ce = concat(c, e);
        int de = concat(d, e);
        int ea = concat(e, a);
        int eb = concat(e, b);
        int ec = concat(e, c);
        int ed = concat(e, d);


        if(!is_prime(ae)) continue;
        if(!is_prime(be)) continue;
        if(!is_prime(ce)) continue;
        if(!is_prime(de)) continue;
        if(!is_prime(ea)) continue;
        if(!is_prime(eb)) continue;
        if(!is_prime(ec)) continue;
        if(!is_prime(ed)) continue;

        printf("%i, %i, %i, %i, %i, sum=%i\n", a, b, c, d, e,
            (a + b + c + d + e));
        exit(0);

    }
    }
    }
    }
    }

    return 0;
}

