<?php

ini_set('memory_limit', '1024M');

$limit = 2000000;
$climit = floor(sqrt($limit));
$sieve = array();

// mark all numbers from 2 to climit as potentially prime
for($i = 0; $i < $limit; $i++) {
	array_push($sieve, true);
}
$sieve[0] = false;
$sieve[1] = false;

// mark all multiples of 2 as non-prime
for($i = 4; $i < $limit; $i += 2) {
	$sieve[$i] = false;
}

for($i = 3; $i < $climit; $i += 2) {
	if($sieve[$i] == true) {
		for($m = $i * $i; $m < $limit; $m += $i * 2) {
			$sieve[$m] = false;
		}
	}
}

$total = 0;
for($i = 0; $i < $limit; $i++) {
	if($sieve[$i] == true) {
		$total += $i;
	}
}

print $total . "\n";

?>

