<?php

/**
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 
is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called 
abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
as the sum of two abundant numbers is 24.  By mathematical analysis, it can be shown that all integers
greater than 28123 can be written as the sum of two abundant numbers.  However, this upper limit cannot
be reduced any further by analysis even though it is known that the greatest number that cannot be 
expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
**/

//ini_set('memory_limit', '1024M');

function proper_divisors($n) {
	$r = floor(sqrt($n));
	$pd = array(1);
	
	// perfect square
	if($r * $r == $n) {
		array_push($pd, $r);
		$r -= 1;
	}

	$step = 1;
	$i = 2;
	if($n % 2 == 1) {
		$step = 2;
		$i = 3;
	}

	while($i <= $r) {
		if($n % $i == 0) {
			$pair = $n / $i;
			array_push($pd, $i);
			array_push($pd, $pair);
		}
		$i += $step;
	}
	return $pd;
}

function reduce_sum($v, $n) {
	$v += $n;
	return $v;
}

function pd_sum($n) {
	return array_reduce(proper_divisors($n), "reduce_sum");
}

$limit = 28123;
$abundants = array();

for($i = 12; $i < $limit; $i++) {
	$pd_sum = pd_sum($i);
	if($i < $pd_sum && $pd_sum <= $limit) {
		array_push($abundants, $i);
	}
}
$abundants = &array_unique($abundants);
sort($abundants, SORT_NUMERIC);
//print "count of abundants: " . count($abundants) . "\n";

$sum = 0;
for($i = 1; $i <= $limit; $i++) {
	for($e = 0; $e < count($abundants); $e++) {
		$compliment = $i - $abundants[$e];
		
		// duplicate of the same abundant number
		if($compliment == 0 && binary_in_array($compliment, $abundants)) {
			goto found;
		}
		
		// not a valid situation
		if($compliment < 0) continue;

		// if $compliment is found in $abundants then the
		// two add up to $i and should be discarded
		if(binary_in_array($compliment, $abundants)) {
			goto not_found;
		}
	}
	// if the previous loop expires then all abundant values have been 
	// checked and none add up to $i so it should be added to the $sum
found:
	$sum += $i;
not_found:
}

function binary_in_array($elem, $array) {
	$top = sizeof($array) - 1;
	$bot = 0;
	while($top >= $bot) {
		$p = floor(($top + $bot) / 2);
		if($array[$p] < $elem) $bot = $p + 1;
		elseif($array[$p] > $elem) $top = $p - 1;
		else return true;
	}
	return false;
}

print $sum;

?>
