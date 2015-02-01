<?php

/**
Powerful digit counts

The 5-digit number, 16807=7^5, is also a fifth power.  Similarly, the 9-digit number, 134217728=8^9,
is a ninth power.

How many n-digit positive integers exists which are also an nth power?
**/


// 10^(n-1) <= x^n < 10^n
// I originally tried n < 100 and pow < 100

$total = 0;
for($n = 1; $n < 10; $n++) {
for($pow = 1; $pow < 22; $pow++) {
	$r = bcpow(strval($n), strval($pow));
	if(strlen($r) == $pow) $total++;
}
}

print $total;

?>
