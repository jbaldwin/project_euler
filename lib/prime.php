<?php

/**
 * Determines if a number is prime or not.
 * @param int $n Calculate if this number is prime.
 * @return bool true if $n is prime, false if $n is composite.
 **/
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

/**
 * Creates a prime sieve up to $limit.
 * The prime sieve uses ($limit - 1) / 2 memory.
 * Use prime_sieve_value($i) to retrieve the index's actual value.
 * @param int $limit The maximum number in the prime sieve.
 * @return array<bool> True indices are prime and false are composite.
 **/
function prime_sieve($limit) {
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

	$primes = array();
	$primes[] = 2;
	for($i = 1; $i < $sievebound; $i++) {
		if($sieve[$i]) {
			$primes[] = 2 * $i + 1;
		}
	}

	unset($sieve);
	return $primes;
}

/**
 * Calculates the prime factors for the number $n.
 * Returns all prime factors with duplicates and unsorted.
 * @param $n The number to calculate all prime factors for.
 * @return Array<int> Prime factors for the number $n.
 **/
function prime_factors($n) {
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
	return $factors;
}

?>

