<?php

/**
In England the currence is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2(200p).

It is possible to make £2 in the following way:

1x£1 + 1x50p + 2x20p + 1x5[ + 1x2[ + 3x1p

How many different ways can £2 be made using any number of coins?
**/

$currency = array(100, 50, 20, 10, 5, 2, 1);

function combos($i, $start) {
	global $currency;

	// base case when 200p has been achieved return a single combination
	if($i == 200) return 1;

	// the trick here is that once you move down a recursion level
	// you never move up in pence amount, e.g.
	//     10 -> 10 -> 5 is OK 
	//     10 -> 5 -> 10 is NOT OK since it is a duplicate of the previous
	$combinations = 0;
	for($j = $start; $j < 7; $j++) {
		if($i + $currency[$j] <= 200) {
			$combinations += combos($i + $currency[$j], $j);
		}
	}
	return $combinations;
}

$combinations = 1 + combos(0, 0);
print $combinations . "\n";

?>

