<?php

/**
We shall say that an n-digit number is pandigital if itmakes use of all the digits 1 to n exactly once;
for example, the 5-digit number 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier,
and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as 1 through
9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
**/

$products = array();

for($a = 1; $a <= 50; $a++) {
	// can't contain a zero
	if(strpos(strval($a), "0")) continue;

	for($b = 1; $b < 2000; $b++) {
		if(strpos(strval($b), "0")) continue;

		$c = $a * $b;
		if($c > 987654321) goto too_large;

		if(strpos(strval($c), "0")) continue;

		$str = strval($c) . strval($a) . strval($b);
		// must be exactly 9 digits
		if(strlen($str) != 9) continue;

		// check for all digits
		for($i = 1; $i <= 9; $i++) {
			$count = 0;
			for($j = 0; $j < 9; $j++) {
				if($str[$j] == $i) $count++;
			}
			if($count != 1) goto invalid;
		}

		$products[$c] = $c;
		invalid:
	}
	too_large:
}

$sum = 0;
foreach($products as $p) {
	$sum += $p;
}
print $sum;

?>
