#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {

	int pandigitals[128];
	memset(pandigitals, 0, sizeof(int) * 128);
	int count = 0;

	for(int a = 1; a <= 50; a++) {
		char a_str[128];
		int a_len = sprintf(a_str, "%i", a);

		if(strstr(a_str, "0") != NULL) continue;

		for(int b = 1; b < 2000; b++) {
			bool valid = true;
			char b_str[128];
			int b_len = sprintf(b_str, "%i", b);

			if(strstr(b_str, "0") != NULL) continue;

			int c = a * b;
			if(c > 987654321) continue;
			char c_str[128];
			int c_len = sprintf(c_str, "%i", c);

			if(c_len + a_len + b_len != 9) continue;
			if(strstr(c_str, "0") != NULL) continue;

			char pandigital[128];
			int len = sprintf(pandigital, "%i%i%i", c, a, b);
			if(len != 9) continue;

			for(int i = 1; i <= 9; i++) {
				int total = 0;
				for(int j = 0; j < 9; j++) {
					if(pandigital[j] - 48  == i) total++;
				}
				if(total != 1) {
					valid = false;
					break;
				}
			}

			if(valid) {
				bool duplicate = false;
				for(int i = 0; i < count; i++) {
					if(pandigitals[i] == c) {
						duplicate = true;
						break;
					}
				}

				if(!duplicate) {
					pandigitals[count] = c;
					count++;
				}
			}
		}
	}

	int sum = 0;
	for(int i = 0; i < count; i++) {
		sum += pandigitals[i];
	}

	printf("%i", sum);

	return 0;
}

