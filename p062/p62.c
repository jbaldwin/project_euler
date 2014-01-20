#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

#include <glib.h>

#include <proc/readproc.h>

typedef struct cube_t {
	unsigned int matches;
	unsigned long long i;

} cube_t;

int count_digits(unsigned long long n, int* digits) {
	bool found = false;
	unsigned long long divisor = 1000000000000;
	int count = 0;
	while(divisor > 0) {
		// ignore all leading zeros
		int digit = n / divisor;
		if(!found && digit) {
			 found = true;
		}
		if(found) { 
			digits[digit]++;
			count++;
		}
		n %= divisor;
		divisor /= 10;
	}
	return count;
}

char digit2char(int digit) {
	return '0' + digit;
}

char* create_key(int* digits, int num_digits) {
	char* key = malloc(sizeof(char) * num_digits + 1);
	memset(key, '\0', num_digits + 1);

	int key_pos = 0;
	for(int current_digit = 0; current_digit < 10; current_digit++) {
		for(int n_digits = 0; n_digits < digits[current_digit];	n_digits++) {
			key[key_pos] = digit2char(current_digit);
			key_pos++;
		}
	}
	return key;
}

void find(gpointer key, gpointer value, gpointer user_data) {
	cube_t* cube = (cube_t*)value;
	if(cube->matches >= 5) {
		printf("%llu\n", cube->i * cube->i * cube->i);
		exit(0);
	}
}

void insert(GHashTable* ht, char* key, unsigned long long i) {
	cube_t* prev = (cube_t*)g_hash_table_lookup(ht, key);

	if(prev == NULL) {
		cube_t* cube = malloc(sizeof(cube_t));
		cube->i = i;
		cube->matches = 1;
		g_hash_table_insert(ht, key, cube);
	} else {
		prev->matches++;
		g_hash_table_insert(ht, key, prev);
	}
}

int main(int argc, char* argv[]) {

	int stop = 10000;

	GHashTable* counts = g_hash_table_new(
		g_str_hash,
		g_str_equal);

	for(unsigned long long i = 100; i < stop; i++) {
		unsigned long long cube = i * i * i;

		int digits[10] = { 0 };
		int num_digits = count_digits(cube, digits);

		char* key = create_key(digits, num_digits);

		insert(counts, key, i);
	}

	g_hash_table_foreach(counts, find, NULL);

	return 0;
}

