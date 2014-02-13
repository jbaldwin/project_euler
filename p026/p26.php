<?php

/**
A unit fraction contains 1 in the numerator.  The decimal representation of the unit fractions
with denomiators 2 to 10 are given:

1/2  = 0.5
1/3  = 0.(3)
1/4  = 0.25
1/5  = 0.2
1/6  = 0.1(6)
1/7  = 0.(142857)
1/8  = 0.125
1/9  = 0.(1)
1/10 = 0.1

Where 0.1(6) means 0.166666...., and has a 1-digit recurring cycle.  It can be seen that 1/7 has a 
6-digit recurring cycle.

Find the value of d < 1000 for which 1 / d contains the longest recurring cycle in its decimal fraction part.
**/

require_once "../lib/prime.php";

$maxlen = 0;
$maxn = -1;

for($n = 2; $n <= 1000; $n++) {
	if(!is_prime($n)) continue;

	$rest = 1;
	for($i = 0; $i < $n; $i++) {
		$rest = ($rest * 10) % $n;
	}

	$r0 = $rest;
	$len = 0;

	do {
		$rest = ($rest * 10) % $n;
		$len++;
	} while($rest != $r0);

	if($len > $maxlen) {
		$maxn = $n;
		$maxlen = $len;
	}
}

print $maxn;

?>
