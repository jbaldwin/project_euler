<?php

/**
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called
amicable numbers.

For example, the proper divisors of 220 and 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore
d(22) = 284.  The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all amicable numbers under 10000.
**/

function proper_divisors($n) {
	$s = floor(sqrt($n));
	$pd = array(1);

	for($i = 2; $i <= $s; $i++) {
		if($n % $i == 0) {
			$factor = $n / $i;
			array_push($pd, $i);
			array_push($pd, $factor);
		}
	}

	return $pd;
}

function reduce_sum($v, $w) {
	$v += $w;
	return $v;
}

function d($n) {
	$pd = proper_divisors($n);
	return array_reduce($pd, "reduce_sum");
}

$amicable = array();

for($a = 1; $a < 10000; $a++) {
	$b = d($a);
	if($a == $b) continue;

	if($a == d($b)) {
		array_push($amicable, $a);
		array_push($amicable, $b);
	}
}

// each pair shows up twice, so reduce to unique numbers
$amicable = &array_unique($amicable, SORT_NUMERIC);
$sum = array_reduce($amicable, "reduce_sum");

print $sum;

?>
