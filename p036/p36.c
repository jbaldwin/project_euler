#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

void print_bits(int n, char* bin, int size) {
	char* pbuff = bin;

	if(n == 0) {
		bin[0] = '0';
		bin[1] = '\0';
		return;
	}

	pbuff += size;
	*pbuff = '\0';
	pbuff--;

	while(n != 0) {
		*pbuff = ((n & 1) == 1) ? '1' : '0';
		n >>= 1;
		pbuff--;
	}
}

char* start(char* bin, int size) {
	for(int i = 0; i < size; i++) {
		if(bin[i] == '1') {
			return &bin[i];
		}
	}
	return bin;
}

bool is_palindrome(char* s, int size) {
	char reverse[33];
	memset(reverse, '\0', 33);

	for(int i = size - 1, j = 0; i >= 0; i--, j++) {
		reverse[j] = s[i];
	}

	//printf("%s = %s\n", s, reverse);

	for(int i = 0; i < size; i++) {
		if(s[i] != reverse[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {

	int sum = 0;
	for(int i = 1; i < 1000000; i++) {
		char buffer[33];
		int dec_len = sprintf(buffer, "%i", i);

		//printf("%s\n", buffer);

		if(!is_palindrome(buffer, dec_len)) {
			continue;
		}

		memset(buffer, '\0', 33);
		print_bits(i, buffer, 33);
		char* bin = start(buffer, 32);
		if(bin == NULL) { printf("null\n"); return 0; }
		int bin_len = strlen(bin);

		//printf("%s\n", bin);

		if(!is_palindrome(bin, bin_len)) {
			continue;
		}

		sum += i;

	}

	printf("%i", sum);

	return 0;
}

