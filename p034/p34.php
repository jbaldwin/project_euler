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

$curious = array();

for($i = 3; $i < 99999; $i++) {
	$fact_sum = 0;
	$str = strval($i);
	for($j = 0; $j < strlen($str); $j++) {
		$fact_sum += factorial($str[$j]);
	}
	if($i == $fact_sum) {
		$curious[$i] = $i;
		print $i . "\n";
	}
}

$sum = 0;
foreach($curious as $c) {
	$sum += $c;
}
print $sum . "\n";

?>

