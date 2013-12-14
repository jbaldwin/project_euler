<?php

/**
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists.
**/

ini_set('memory_limit', '1024M');

$limit = 10000000;
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

$pandigital = 0;
for($i = 1; $i < $sievebound; $i++) {
	if($sieve[$i] == true) {
		$p = 2 * $i + 1;

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
			$pandigital = $p;
			print $pandigital . "\n";
		}
	}
}

print "\n" . $pandigital . "\n";

?>

