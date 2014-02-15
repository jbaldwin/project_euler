#include <stdio.h>

int main(int argc, char* argv[]) {

	int limit = 1001 * 1001;

	int skip = 0;
	int total = 1;
	int count = 0;

	for(int i = 3; i <= limit; i += 2) {
		for(int j = 0; j < skip; j++) i += 2;
		total += i;
		count++;

		if(count % 4 == 0) skip++;
	}

	printf("%i", total);

	return 0;
}

