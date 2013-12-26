<?php

/**
Distinct primes factors

The first two consecutive numbers to have two distinct prime factors are:

	14 = 2 x 7
	15 = 3 x 5

The first three consecutive numbers to have three distinct prime factors are:

	644 = 2^2 x 7 x 23
	645 = 3 x 5 x 43
	646 = 2 x 17 x 19

Find the first four consecutive integers to have four distinct prime factors.  What is the first of these numbers?
**/

require_once "../lib/prime.php";

function prime_factors_count($n) {
	return count(array_unique(prime_factors($n)));
}

$n = 2;
$expected_primes = 4;
again:
for($i = $expected_primes - 1; $i >= 0; $i--) {
	if(prime_factors_count($n + $i) != $expected_primes) {
		$n += $i + 1;
		goto again; 
	}
}

print $n . "\n";

?>

