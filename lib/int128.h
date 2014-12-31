#include <stdio.h>
#include <stdlib.h>

/**
 * Converts a unsigned __int128 to char*.  The result
 * needs to be free'ed by the user when it is no longer needed.
 * @param unsigned __int128 n Integer to convert to char*
 * @return String representation of n.
 **/
char* uint128_to_str(unsigned __int128 n) {
    if(n == 0) return "0";

    char* str = (char*)malloc(40 * sizeof(char));
    char* s = str + sizeof(str) - 1;
    while(n != 0) {
        if(s == str) return NULL;

        *--s = "0123456789"[n % 10];
        n /= 10;
    }
    return str;
}

/**
 * Prints an unsigned __int128 to stdout.
 * @param unsigned __int128 n Integer to print to stdout.
 * @return Number of characters printed to stdout.
 **/
int uint128_print(unsigned __int128 n) {
	if(n == 0) return printf("0");

	char str[40] = { 0 };
	char *s = str + sizeof(str) - 1;
	while(n != 0) {
		if(s == str) return -1;	// never happens (?lulz?)

		*--s = "0123456789"[n % 10];	// wow thats cool...
		n /= 10;
	}

	return printf("%s", s);
}

/**
 * n^exp.
 * @param int n Base
 * @param int exp Exponent
 * @return unsigned __int128 power result.
 **/
unsigned __int128 uint128_power(int n, int exp) {
    unsigned __int128 sum = 1;
    for(int i = 0; i < exp; i++) {
        sum *= n;
    }
    return sum;
}

