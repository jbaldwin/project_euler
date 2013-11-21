<?php

ini_set('memory_limit', '1024M');

$limit = 2000000;
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

$sum = 2;
for($i = 1; $i < $sievebound; $i++) {
	if($sieve[$i] == true) {
		$sum += 2 * $i + 1;
	}
}

print $sum . "\n";

?>

