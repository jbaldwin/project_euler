<?php

/**
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 791, 
are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97.

How many circular primes are there below one million?
**/

require_once "../lib/prime.php";

function is_circular_prime($prime, $circular_primes) {

	if($prime < 10) return true;

	
	$str = strval($prime);
	$str = substr($str, 1) . $str[0];

	for($i = 1; $i < strlen($str); $i++) {
		if(!array_key_exists($str, $circular_primes) &&
		   !is_prime(intval($str))) {
			return false;
		}

		$str = substr($str, 1) . $str[0];
	}	
	return true;
}

function contains_even_digits($n) {
	$str = strval($n);
	$len = strlen($str);
	for($i = 0; $i < $len; $i++) {
		if($str[$i] % 2 == 0) return true;
	}
	return false;
}

// first find all primes below 1 million
$circular_primes = array(2);
for($i = 3; $i < 1000000; $i += 2) {
	if(!contains_even_digits($i) && is_prime($i) && is_circular_prime($i, $circular_primes)) {
		$circular_primes[$i] = $i;
	}	
}

print count($circular_primes);

?>
