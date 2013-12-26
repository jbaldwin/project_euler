<?php

/**
Goldbach's other conjecture

It was proposed by CHristian Goldbach that every odd composite number can be written as the sum
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

ini_set('memory_limit', '1024M');

$limit = 100000;
$sieve = prime_sieve($limit);
$sievebound = count($sieve);

for($c = 1; $c < $sievebound; $c++) {
	if($sieve[$c] == false) {
		$cval = prime_sieve_value($c);

		$found = false;
		for($p = 1; $p < $c; $p++) {
			if($sieve[$p] == true) {
				$pval = prime_sieve_value($p);
				// calculate the sqrt and take the integer value
				// if the reverse operation matches $cval goldbach's
				// conjecture works
				$s = floor(sqrt((($cval - $pval) / 2)));
				if($pval + 2 * $s * $s == $cval) {
					$found = true;
				}
			}
		}
		// all primes and 2 * squares exhausted.. so this $cval does not
		// match goldback's conjecture
		if(!$found) {
			break;
		}
	}
}
print prime_sieve_value($c) . "\n";

?>

