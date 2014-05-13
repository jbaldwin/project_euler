#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PAN_LEN 128

int main(int argc, char* argv[]) {
	int max_pan = 0;
	
	for(int i = 1; i < 9876; i++) {
		for(int n = 1; n <= 9; n++) {
			char pan_str[PAN_LEN];
			int len = 0;

			for(int j = 1; j <= n; j++) {
				len += sprintf(pan_str + len, "%d", i * j);

				if(len > 9) {
					break;
				}
			}

			if(len != 9) continue;

			int pan = atoi(pan_str);
			if(pan > 987654321) break;
			if(pan <= 918273645) continue;

			int counts[10] = { 0,0,0,0,0,0,0,0,0,0 };
			int div = pan;
			while(div) {
				counts[div % 10]++;
				div /= 10;
			}
			bool is_pan = true;
			// skip 0 as it is not valid for the pandigital
			for(int j = 1; j < 10; j++) {
				if(counts[j] != 1) {
					is_pan = false;
					break;
				}
			}

			if(is_pan && pan > max_pan) {
				max_pan = pan;
			}
		}
	}

	printf("%i", max_pan);

	return 0;
}

