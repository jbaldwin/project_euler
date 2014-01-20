<?php

require_once "../lib/prime.php";

ini_set('memory_limit', '256M');

$limit = 2000000;
$primes = prime_sieve($limit);

$sum = 0;
for($i = 0; $i < count($primes); $i++) {
	$sum += $primes[$i];
}

print $sum . "\n";

?>

