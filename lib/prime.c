#include <math.h>

int is_prime(int n) {
    if(n <= 1) return 0;
    if(n < 4) return 1;
    if(n % 2 == 0) return 0;
    if(n < 9) return 1;
    if(n % 3 == 0) return 0;

    int r = floor(sqrt(n));
    int f = 5;
    while(f <= r) {
        if(n % f == 0) return 0;
        if(n % (f + 2) == 0) return 0;
        f += 6;
    }
    return 1;
}
