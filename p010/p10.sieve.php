<?php

require_once "../lib/prime.php";

ini_set('memory_limit', '1024M');

$limit = 2000000;
$sieve = prime_sieve($limit);
$sievebound = count($sieve);

$sum = 2;
for($i = 1; $i < $sievebound; $i++) {
	if($sieve[$i] == true) {
		$sum += prime_sieve_value($i);
	}
}

print $sum . "\n";

?>

