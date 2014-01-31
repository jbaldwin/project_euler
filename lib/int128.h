#include <stdio.h>

int print_uint128(unsigned __int128 n) {
	if(n == 0) return printf("0");

	char str[40] = {0};
	char *s = str + sizeof(str) - 1;
	while(n != 0) {
		if(s == str) return -1;	// never happens (?lulz?)

		*--s = "0123456789"[n % 10];	// wow thats cool...
		n /= 10;
	}
	
	return printf("%s", s);
}

