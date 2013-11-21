<?php

/**
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all the numbers from 1 to 20;
**/

function gcd($a, $b) {
	if($b == 0) {
		return $a;
	} else {
		return gcd($b, $a % $b);
	}
}

function lcm($a, $b) {
	return ($a / gcd($a, $b)) * $b;
}

// Calculate the least common multiple of [1..20].
$result = 1;
for($i = 2; $i <= 20; $i++) {
	$result = lcm($result, $i);
}

print $result . "\n";

?>

