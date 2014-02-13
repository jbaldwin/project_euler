<?php

/**
Euler discovered the remarkable quadratic formula:

n^2 +n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when
n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive
values n = 0 to 79.
The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:

	n^2 + an + b, where |a| < 1000 and |b| < 1000

	where |n| is the modulus/absolute value of n
	e.g. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum
number of primes for consecutive values of n, starting with n = 0.

**/

require_once '../lib/prime.php';

// Note that b > 1 must be true since when n = 0 then b must be prime

$max_n = 0;
$product = 0;
$max_a = 0;
$max_b = 0;

for($a = -999; $a < 1000; $a++) {
	for($b = 2; $b < 1000; $b++) {
		$n = 0;
		if(!is_prime($b)) continue;

		while(true) {
			$c = ($n * $n) + $a * $n + $b;
			if(!is_prime($c)) break;
			$n++;
		}

		if($n > $max_n) {
			$max_n = $n;
			$product = $a * $b;
			$max_a = $a;
			$max_b = $b;
		}
	}
}

//print "n=" . $max_n . " product=" . $product . " a=" . $max_a . " b=" . $max_b . "\n";
print $max_a * $max_b;

?>
