#include <stdio.h>
#include <string.h>

#include "../lib/int128.h"

typedef unsigned __int128 u128;

int main(int argc, char* argv[]) {

    u128 sum = 0;

    for(int i = 1; i <= 1000; i++) {
        sum += uint128_power(i, i);
    }

    char* value = uint128_str(sum);
    int len = strlen(value);
    char* start = value + (len - 10); // only print last 10 chars
    printf("\n%s", start);
    free(value);

    return 0;
}

