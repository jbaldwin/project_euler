#include <stdio.h>
#include <stdbool.h>

typedef long long int64;

int64 factorial(int64 n) {
	int f = 1;
	if(n <= 1) return 1;
	for(int64 i = n; i > 0; i--) f *= i;
	return f;
}

int64 lex_index(int* p) {
	int64 result = 0;

	for(int64 j = 0; j < 10; j++) {
		int64 k = 0;
		for(int64 i = j + 1; i < 10; i++) {
			if(p[i] < p[j]) k++;
		}

		result += k * factorial(10 - j - 1);
	}

	return result + 1;
}

int main(int argc, char* argv[]) {

	int p[10] = { -1, -1, -1, -1, -1, -1, -1, -1 , -1, -1 };
	int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for(int i = 0; i < 10; i++) {
		int64 max = -1;
		int max_index = -1;

		for(int j = 0; j < 10; j++) {
			if(nums[j] == -1) continue;

			p[i] = nums[j];
			int z = 1;
			for(int k = 0; k < 10; k++) {
				if(nums[k] == -1) continue;

				bool exists = false;
				for(int e = 0; e <= i; e++) {
					if(p[e] == nums[k]) exists = true;
				}

				if(!exists && i + z < 10) {
					p[i + z] = nums[k];
					z++;
				}
			}
			int64 t = lex_index(p);

			if(t > 1000000) continue;
			if(t > max) {
				max = t;
				max_index = j;
			}
		}

		p[i] = nums[max_index];
		nums[max_index] = -1;
		for(int j = i + 1; j < 10; j++) p[j] = -1;
	}

	for(int i = 0; i < 10; i++) {
		printf("%i", p[i]);
	}

	//int64 i = lex_index(2783915460);
	//printf("%llu", i);

	return 0;
}

