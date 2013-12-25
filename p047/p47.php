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

function prime_factors_count($n) {
	$factors = array();
	$d = 2;
	while($n > 1) {
		while($n % $d == 0) {
			array_push($factors, $d);
			$n /= $d;
		}
		$d += 1;
		if($d * $d > $n) {
			if($n > 1) {
				array_push($factors, $n);
			}
			break;
		}
	}
	return count(array_unique($factors));
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

