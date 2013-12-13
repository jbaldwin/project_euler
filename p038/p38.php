<?php

/**
Take the number 192 and multiply it by each of 1, 2, and 3:

	192 x 1 = 192
	192 x 2 = 348
	192 x 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576.  We will call 192384576 the
concatenated product of 192 and (1,2,3).

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital
918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the oncatenated product of
an integer with (1,2,...,n) where n > 1?
**/

$max_i = 0;
$max_n = 0;
$max_pan = "";

for($i = 1; $i < 9999; $i++) {
	for($n = 1; $n <= 9; $n++) {
		$s = "";
		for($j = 1; $j <= $n; $j++) {
			$s .= $i * $j;
		}

		if($s > 987654321) break;	// number is too high, break as it will only get higher
		if($s <= 918273645) continue;	// problems states it must be higher than this number
		if(strlen($s) != 9) continue;	// cannot be pandigital, must be 9 digits

		$is_pan = true;
		for($j = 1; $j <= 9; $j++) {
			if(substr_count($s, $j) != 1) {
				$is_pan = false;
				break;
			}
		}

		if($is_pan == true && $s > $max_pan) {
			$max_pan = $s;
			$max_i = $i;
			$max_n = $n;
			print $max_pan . "\n";
		}
	}
}

print "\n" . $max_pan . " i=" . $max_i . " n=" . $max_n . "\n";


?>

