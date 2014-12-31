<?php

/**
Goldbach's other conjecture

It was proposed by Cristian Goldbach that every odd composite number can be written as the sum
of a prime and twice a square.

9  =  7 + 2x1^2
15 =  7 + 2x2^2
21 =  3 + 2x3^2
25 =  7 + 2x3^2
27 = 19 + 2x2^2
33 = 31 = 2x1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
**/

require_once "../lib/prime.php";

$limit = 10000;
$primes = prime_sieve($limit);
$composites = array_diff(
	range($primes[1], $primes[count($primes) - 1], 2),
    $primes
);

foreach($composites as $c) {
	$found = false;
	foreach($primes as $p) {
		if($p > $c) break;

		$s = floor(sqrt(($c - $p) / 2));
		if($p + 2 * $s * $s == $c) {
			$found = true;
			break;
		}
	}
	if(!$found) {
		print $c . "\n";
		die();
	}
}

?>
