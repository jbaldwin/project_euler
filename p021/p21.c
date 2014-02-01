#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

typedef struct proper_divisors_t {
    int divisors[64];
    int len;
} proper_divisors_t;

proper_divisors_t uniq_pd(proper_divisors_t pd) {
    for(int i = 0; i < pd.len; i++) {
        for(int j = i + 1; j < pd.len; j++) {
            if(pd.divisors[i] == pd.divisors[j]) {
                if(j == pd.len - 1) {
                    pd.len--;   // this is the end ... so just stop counting it
                    continue;
                }
                memmove(pd.divisors[j], pd.divisors[j + 1], sizeof(int) * pd.len - j);
                pd.len--;
            }
        }
    }
    return pd;
}

proper_divisors_t proper_divisors(int n) {
    proper_divisors_t pd;
    pd.len = 0;

    int s = floor(sqrt(n));

    for(int i = 2; i <= s; i++) {
        if(n % i == 0) {
            int factor = n / i;

            if(pd.len + 2 > 64) {
                printf("too many proper divisors\n");
                exit(1);
            }

            pd.divisors[pd.len] = i;
            pd.divisors[pd.len + 1] = factor;
            pd.len += 2;
        }
    }

    return uniq_pd(pd);
}

int main(int argc, char* argv[]) {

    for(int a = 1; a < 10000; a++) {
        int b = 
    }

    return 0;
}

