#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char* letters) {
	size_t len = strlen(letters);

	for(int i = 0; i < len / 2; i++) {
		if(letters[i] != letters[len - i - 1]) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {

	int max = 0;
	for(int i = 100; i < 1000; i++) {
		for(int j = i; j < 1000; j++) {
			char letters[6] = { 0 };
			snprintf(letters, 6, "%i", i * j);
			if(is_palindrome(letters)) {
				printf("%s is palindrome\n", letters);
				if(i * j > max) {
					max = i * j;
					//printf("%i\n", max);
				}
			}
		}
	}
	printf("%i\n", max);

	return 0;
}
