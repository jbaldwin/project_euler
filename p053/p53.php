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

$count = 0;
for($n = 23; $n <= 100; $n++) {
	$start = floor($n / 2);

	// $n/2 only occurs once
	if($start * 2 == $n) {
		if(gmp_cmp(combination($n, $start), "1000000") > 0) {
			$count++;
		}
	}

	// make sure we are above $n/2
	if($start <= ($n / 2)) $start++;

	// all other values occur above and below $n/2 so count it twice
	for($r = $start; $r <= $n; $r++) {
		if(gmp_cmp(combination($n, $r), "1000000") > 0) {
			$count+=2;
		}
	}
}

print $count;

?>
