
void fraction_reduce_i32(int* numerator, int* denominator) {
	for(int i = *numerator; i >= 1; i--) {
		if(*numerator % i == 0 && *denominator % i == 0) {
			*numerator /= i;
			*denominator /= i;
			break;
		}
	}
}

void fraction_reduce_i64(long long* numerator, long long* denominator) {
	for(long long i = *numerator; i >= 1; i--) {
		if(*numerator % i == 0 && *denominator % i == 0) {
			*numerator /= i;
			*denominator /= i;
			break;
		}
	}
}

void fraction_reduce_ui64(unsigned long long* numerator, unsigned long long* denominator) {
	for(unsigned long long i = *numerator; i >= 1; i--) {
		if(*numerator % i == 0 && *denominator % i == 0) {
			*numerator /= i;
			*denominator /= i;
			break;
		}
	}
}

