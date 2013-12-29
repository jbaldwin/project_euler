<?php

/**
Combinatoric selections

There are exactly ten ways of selecting three from five, 12345:
	123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation (5 C 3) = 10.

In general (n C r) = (n!) / r!(n - r)!, where r <= n, n! = nx(n -1)x...x3x2x1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: (23 C 10) = 1144066.

How many, not necessarily distinct, values of (n C r), for 1 <= n < 100, are greater than one-million?
**/

$cache = array();

function combination($n, $r) {
	return gmp_div(gmp_fact($n), gmp_mul(gmp_fact($r), gmp_fact($n - $r)));
}

$coount = 0;
for($n = 2; $n <= 100; $n++) {
	for($r = 1; $r <= $n; $r++) {
		if(gmp_cmp(combination($n, $r), "1000000") > 0) {
			$count++;
		}
	}
}

print $count . "\n";

?>

