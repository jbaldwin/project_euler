#include <stdio.h>
#include <malloc.h>
#include <sys/resource.h>

char* create_table(unsigned long long n) {

	char* table = malloc(sizeof(char) * 10);

	for(int i = 0; i < 10; i++) {
		table[i] = 0;
	}

	char found = 0;
	unsigned long long divisor = 1000000000000;
	while(divisor > 0) {
		int digit = n / divisor;
		if(!found && digit) {
			found = 1;
		}
		if(found) table[digit]++;
		n %= divisor;
		divisor /= 10;
	}

	return table;
}

int tables_equal(char* t1, char* t2) {
	for(int i = 0; i < 10; i++) {
		if(t1[i] != t2[i]) return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {

	int stop = 10000;
	char** tables = malloc(sizeof(char*) * stop);

	// generate digit tables
	for(unsigned long long i = 0; i < stop; i++) {
		unsigned long long cube = i * i * i;
		tables[i] =  create_table(cube);
	}
	// count the number of matches
	for(int i = 0; i < stop; i++) {
		char matches = 1;
		for(int j = 0; j < stop; j++) {
			if(i == j) continue;
			matches += tables_equal(tables[i], tables[j]);
		}
		if(matches >= 5) {
			unsigned long long llu = i;
			printf("%i cubed = %llu\n", i, llu * llu * llu);
			break;
		}
	}
	return 0;
}
