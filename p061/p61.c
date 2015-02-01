#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 256

int triangle(int n) { return n * (n + 1) / 2; }
int square(int n) { return n * n; }
int pentagonal(int n) { return n * (3 * n - 1) / 2; }
int hexagonal(int n) { return n * (2 * n - 1); }
int heptagonal(int n) { return n * (5 * n - 3) / 2; }
int octagonal(int n) { return n * (3 * n - 2); }

typedef struct value_t {
    int n;
    int v;
} value_t;

value_t value_init(int n, int v) {
    value_t value;
    value.n = n;
    value.v = v;
    return value;
}

void cyclic(value_t values[6][MAX_VALUES], int remaining[6], char chain[6][5], int clen) {
    if(clen == 6) {
        // make sure first and last complete the chain
        if(chain[0][0] != chain[5][2] || chain[0][1] != chain[5][3]) return;

        int numbers[6];
        for(int i = 0; i < 6; i++) {
            sscanf(chain[i], "%i", &numbers[i]);
        }
        int sum = 0;
        for(int i = 0; i < 6; i++) {
            sum += numbers[i];
        }

        printf("%i", sum);
        exit(0);
    } else {
        // recursively call cyclic until a full chain is created
        for(int i = 0; i < 6; i++) {
            if(remaining[i] == -1) continue;
            for(int j = 0; j < MAX_VALUES; j++) {
                if(values[i][j].n == -1) break;

                sprintf(chain[clen], "%i", values[i][j].v);

                if( chain[clen - 1][2] == chain[clen][0] &&
                    chain[clen - 1][3] == chain[clen][1]) {
                    remaining[i] = -1;
                    cyclic(values, remaining, chain, clen + 1);
                    remaining[i] = i;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {

    value_t values[6][MAX_VALUES];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < MAX_VALUES; j++) {
            values[i][j] = value_init(-1, -1);
        }
    }

    int (*types[6])(int n);
    types[0] = triangle;
    types[1] = square;
    types[2] = pentagonal;
    types[3] = hexagonal;
    types[4] = heptagonal;
    types[5] = octagonal;

    // generate a full list of each type between 1000 and 10,000
    for(int i = 0; i < 6; i++) {
        int n = 1;
        int v = 0;
        int value_ptr = 0;
        do {
            v = (*types[i])(n);
            if(v >= 1000 && v < 10000) {
                values[i][value_ptr] = value_init(n, v);
                value_ptr++;
            }
            n++;
        } while(v < 10000);
    }

    // recursively generate chains of the numbers until the correct chain is found
    int remaining[6] = { -1 };
    for(int i = 1; i < 6; i++) {
        remaining[i] = i;
    }
    for(int i = 0; i < MAX_VALUES; i++) {
        if(values[0][i].n == -1) break;

        char chain[6][5] = { { '\0' } };
        sprintf(chain[0], "%i", values[0][i].v);

        cyclic(values, remaining, chain, 1);
    }

    return 0;
}

