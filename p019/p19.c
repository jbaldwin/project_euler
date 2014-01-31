#include <stdio.h>
#include <stdbool.h>

int months[] = {
	0,
	31,
	59,
	90,
	120,
	151,
	181,
	212,
	243,
	273,
	304,
	334
};

int is_leap_year(int year) {
	if(year % 100 == 0) {
		return (year % 4 == 0 && year % 400 == 0) ? 1 : 0;
	}
	return (year % 4 == 0) ? 1 : 0;
}

int main(int argc, char* argv[]) {

	int start_day = 2;		// tuesday as 0-6 is sunday...saturday
	int total_sundays = 0;
	int start_year = 1901;
	int end_year = 2000;

	for(int year = start_year; year <= end_year; year++) {
		int leap_year = is_leap_year(year);
		int day = start_day;
		while(day % 7 != 0) {
			day++;
		}

		while(day < 365 + start_day + leap_year) {
			for(int j = 0; j < 12; j++) {
				int first = months[j] + start_day + ((j >= 2) ? leap_year : 0);
				if(day == first) total_sundays++;
			}
			day += 7;
		}

		start_day = (start_day + 1 + leap_year) % 7;
	}

	printf("%i", total_sundays);

	return 0;
}

