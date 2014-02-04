#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int compare_str(const void* v1, const void* v2) {
	return strcmp(*(char**)v1, *(char**)v2);
}

typedef struct names_t {
	int count;
	int capacity;
	char** names;
} names_t;

names_t read_names(char* file) {
	names_t n;
	n.count = 0;
	n.capacity = 256;
	n.names = malloc(sizeof(char*) * n.capacity);

	FILE* hNames = fopen(file, "r");
	while(1) {
		if(n.count == n.capacity) {
			n.capacity += 256;
			n.names = realloc(n.names, sizeof(char*) * n.capacity);
		}

		char word[128];
		int word_found = fscanf(hNames, "\"%[ABCDEFGHIJKLMNOPQRSTUVWXYZ]\",", word);
		if(word_found != 1) break;

		int len = strlen(word);
		n.names[n.count] = malloc(len + 1);
		memset(n.names[n.count], '\0', len + 1);
		memcpy(n.names[n.count], word, len);
		n.count++;
	}
	fclose(hNames);

	qsort(n.names, n.count, sizeof(char*), compare_str);

	return n;
}

int alpha_value(char c) {
	return c - 64;
}

int main(int argc, char* argv[]) {

	names_t n = read_names("names.txt");

	int total = 0;
	for(int i = 0; i < n.count; i++) {
		int rank = 0;
		int len = strlen(n.names[i]);
		for(int j = 0; j < len; j++) {
			rank += alpha_value(n.names[i][j]);
		}
		rank *= i + 1;
		total += rank;
	}
	printf("%i", total);

	return 0;
}

