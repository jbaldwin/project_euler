<?php

ini_set('memory_limit', '1024M');

$limit = 2000000;
$sieve = array();
for($i = 0; $i < $limit; $i++) {
	array_push($sieve, $i);
}

$sieve[0] = 0;// set 0 and 1 as non-prime
$sieve[1] = 0;

for($i = 0; $i < $limit; $i++) {
	if($sieve[$i] != 0) {
		$p = $sieve[$i];
		for($j = $p + $p; $j < $limit; $j += $p) {
			$sieve[$j] = 0;
		}
	}
}

$total = 0;
for($i = 0; $i < $limit; $i++) {
	$total += $sieve[$i];
}

print $total . "\n";

?>

