<?php

/**
Consecutive prime sum

The prime 41, can be written as the sum of six consecutive primes:

	41 = 2 + 3 + 5 + 7 + 11 + 13

This i sthe longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of conescutive primes below one-thousand that adds to a prime, contains 21 terms, and
is equal to 953.

Which prime, belwo one-million, can be written as the sum of the most consecutive primes?
**/

require_once "../lib/prime.php";

$limit = 1000000;
$sieve = prime_sieve($limit);
$sievebound = count($sieve);

$maxlen = 0;
$max = -1;

for($i = $sievebound - 1; $i >= $sievebound - 10000; $i--) {
	if($sieve[$i] == true) {
		$prime = prime_sieve_value($i);
		for($j = $i - 1; $j >= 0; $j--) {

			if($sieve[$j] == false) continue;

			$sum = 0;
			$len = 0;

			for($k = $j; $k >= 0; $k--) {
				if($sieve[$k] == true) {

					$next = prime_sieve_value($k);
					$sum += $next;
					$len++;

					if($sum == $prime) {
						print $prime . " " . $len . "\n";
						if($len > $maxlen) {
							$maxlen = $len;
							$max = $prime;
						}
					} else if($sum > $prime) {
						break;
					}
				}
			}
		}
	}
}

print $max . " of length " . $maxlen . "\n";

?>

