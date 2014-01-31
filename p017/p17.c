#include <stdio.h>

int ones(int n) {
	switch(n) {
		case '0': return 0;	// 'zero' is not inclusive and does not appear like "forty-zero"
		case '1': return 3;	//one
		case '2': return 3;	//two
		case '3': return 5;	//three
		case '4': return 4;	//four
		case '5': return 4;	//five
		case '6': return 3;	//six
		case '7': return 5;	//seven
		case '8': return 5;	//eight
		case '9': return 4;	//nine
		default: return 0;
	}
}

int tens(int n) {
	switch(n) {
		case '0': return 0;
		case '2': return 6;	//twenty
		case '3': return 6;	//thirty
		case '4': return 5;	//forty
		case '5': return 5;	//fifty
		case '6': return 5;	//sixty
		case '7': return 7;	//seventy
		case '8': return 6;	//eighty
		case '9': return 6;	//ninety
		default: return 0;
	}
}

int teens(int n, int n1) {
	switch(n1) {
		case '0': return 3;	//ten
		case '1': return 6;	//eleven
		case '2': return 6;	//twelve
		case '3': return 8;	//thirteen
		case '4': return 8;	//fourteen
		case '5': return 7;	//fifteen
		case '6': return 7;	//sixteen
		case '7': return 9;	//seventeen
		case '8': return 8;	//eighteen
		case '9': return 8;	//nineteen
		default: return 0;
	}
}


int main(int argc, char* argv[]) {

	int total = 11;	// onethousand
	for(int i = 1; i < 1000; i++) {
		char s[4] = {0};
		int len = snprintf(s, 4, "%i", i);

		if(len == 1) {
			total += ones(s[0]);
		}
		else if(len == 2) {
			if(s[0] == '1') {
				total += teens(s[0], s[1]);
			} else {
				total += tens(s[0]) + ones(s[1]);
			}
		}
		else if(len == 3) {
			total += ones(s[0]) + 7; //hundred
			if(s[1] != '0' || s[2] != '0') {
				total += 3; //and
			}

			if(s[1] == '1') {
				total += teens(s[1], s[2]);
			} else {
				total += tens(s[1]) + ones(s[2]);
			}
		}
	}
	printf("%i", total);

	return 0;
}

