<?php

/**
Powerful digit sum

A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably
large: one followed by two-hundred zeros.  Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
**/

$maxSum = 0;

for($a = 90; $a < 100; $a++) {
for($b = 90; $b < 100; $b++) {
	$c = gmp_pow(strval($a), $b);
	
	$s = gmp_strval($c);
	$slen = strlen($s);
	$sum = 0;
	for($i = 0; $i < $slen; $i++) {
		$sum += intval($s[$i]);
	}
	if($sum > $maxSum) {
		$maxSum = $sum;
	}
}
}

print $maxSum . "\n";
?>

