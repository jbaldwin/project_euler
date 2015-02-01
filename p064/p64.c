#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_perfect_square(int n) {
    double sq = sqrt(n);
    return (sq == floor(sq)) ? true : false;
}

int sqrt_period(int n) {
    double a = floor(sqrt(n));

    double a0 = a;
    double m = 0.0;
    double d = 1.0;

    int period = 0;

    while(a != a0 * 2) {
        period++;
        m = d * a - m;
        d = (n - m * m) / d;
        a = floor((a0 + m) / d);
    }

    return period;
}

int main(int argc, char* argv[]) {

    int count = 0;
    for(int n = 2; n <= 10000; n++) {
        if(is_perfect_square(n)) continue;

        int period = sqrt_period(n);

        if(period % 2 == 1) count++;
    }

    printf("%i", count);

    return 0;
}

