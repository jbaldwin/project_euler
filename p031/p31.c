#include <stdio.h>

int currency[] = { 100, 50, 20, 10, 5, 2, 1 };

int combos(int i, int start) {
	
	if(start == 6) return 1;
	if(i == 200) return 1;

	int combinations = 0;
	for(int j = start; j < 7; j++) {
		if(i + currency[j] <= 200) {
			combinations += combos(i + currency[j], j);
		}
	}
	return combinations;
}

int main(int argc, char* argv[]) {

	int combinations = 1 + combos(0, 0);
	printf("%i\n", combinations);
	return 0;
}
