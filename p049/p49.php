<?php

/**
Prime permutations

The arithemetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in
two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations
of one another.

There are no arithemtic sequences made up of 1-, 2-, or 3-digit primes, exhibiting this property, but
there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
**/

require_once "../lib/prime.php";
require_once "../lib/permutations.php";

$sieve = prime_sieve(10000);
$sievebound = count($sieve);
$magic = 3330;

$found = array();

for($i = 1; $i < $sievebound; $i++) {
	if($sieve[$i] == false) continue;
	$sval = prime_sieve_value($i);
	if($sval < 1000) continue;
	if($sval > 4000) break;

	$permutations = array_unique(permutate(strval($sval)));

	foreach($permutations as $k => $p) {
		if($p[0] == '0' ||
		   !is_prime($p)) {
			unset($permutations[$k]);
		}
	}

	if(count($permutations) < 3) continue;
	sort($permutations, SORT_NUMERIC);
	array_values($permutations);

	for($j = 0; $j < count($permutations); $j++) {
		$check1 = $permutations[$j] + $magic;
		$check2 = $check1 + $magic;
		if(in_array($check1, $permutations) &&
		   in_array($check2, $permutations)) {
			$found[$permutations[$j]] = 1;
			break;
		}
	}
}

foreach($found as $f => $v) {
	print $f . ", " . ($f + $magic) . ", " . ($f + 2 * $magic) . "\n";
}


?>

