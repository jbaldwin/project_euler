#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1100000
#define REQ_DIGITS 1000000

int main(int argc, char* argv[]) {

	char digits[MAX_DIGITS];
	memset(digits, '\0', MAX_DIGITS);

	int i = 1;
	char* pos = digits;
	while((pos - digits) < REQ_DIGITS) {
		pos += sprintf(pos, "%i", i);
		i++;
	}

	char d_1 = digits[0]      - 48;
	char d_2 = digits[9]      - 48;
	char d_3 = digits[99]     - 48;
	char d_4 = digits[999]    - 48;
	char d_5 = digits[9999]   - 48;
	char d_6 = digits[99999]  - 48;
	char d_7 = digits[999999] - 48;

	int result = d_1 * d_2 * d_3 * d_4 * d_5 * d_6 * d_7;

	printf("%i", result);

	return 0;
}

