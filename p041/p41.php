<?php

/**
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists.
**/

require_once "../lib/prime.php";

// A prime sieve can be used if sufficient
// memory is available, but 512MB is not enough
$limit = 10000000;

for($p = 9999999; $p > 3; $p -= 2) {
	if(is_prime($p)) {
		$s = strval($p);
		$len = strlen($s);

		$is_pan = true;
		for($c = 1; $c <= $len; $c++) {
			if(substr_count($s, $c) != 1) {
				$is_pan = false;
				break;
			}
		}

		if($is_pan) {
			print $p . "\n";
			exit(0);
		}
	}
}

?>

