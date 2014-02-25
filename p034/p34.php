<?php

/**
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are no included.
**/

function factorial($n) {
	$sum = 1;
	for($i = $n; $i > 1; $i--) {
		$sum *= $i;
	}
	return $sum;
}

$sum = 0;
for($i = 3; $i < 99999; $i++) {
	$fact_sum = 0;
	$j = $i;
	while($j > 0) {
		$fact_sum += factorial($j % 10);
		$j = intval($j / 10);
	}
	if($i == $fact_sum) {
		$sum += $i;
	}
}

print $sum;

?>

