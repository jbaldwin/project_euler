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

ini_set('memory_limit', '1024M');

function is_prime($n) {
	if($n <= 1) return false;
	if($n < 4) return true;
	if($n % 2 == 0) return false;
	if($n < 9) return true;
	if($n % 3 == 0) return false;

	$r = floor(sqrt($n));
	$f = 5;
	while($f <= $r) {
		if($n % $f == 0) return false;
		if($n % ($f + 2) == 0) return false;
		$f += 6;
	}
	return true;
}

$limit = 100000;
$sievebound = ($limit - 1) / 2;
$sieve = array();
for($i = 1; $i < $sievebound; $i++) {
	array_push($sieve, true);
}
$crosslimit = sqrt($sievebound);
for($i = 1; $i < $crosslimit; $i++) {
	if($sieve[$i] == true) {
		for($j = 2 * $i * ($i + 1); $j < $sievebound; $j += 2 * $i + 1) {
			$sieve[$j] = false;
		}
	}
}

function value($i) {
	return 2 * $i + 1;
}

for($c = 1; $c < $sievebound; $c++) {
	if($sieve[$c] == false) {
		$cval = value($c);

		$found = false;
		for($p = 1; $p < $c; $p++) {
			if($sieve[$p] == true) {
				$pval = value($p);
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
print value($c) . "\n";

?>

