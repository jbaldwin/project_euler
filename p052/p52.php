<?php

/**
Permuted multiples

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in
a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
**/

function same($s1, $s2) {
	$s1len = strlen($s1);
	$s2len = strlen($s2);
	if($s1len != $s2len) return false;

	for($i = 0; $i < $s1len; $i++) {
		$count = 0;
		for($j = 0; $j < $s1len; $j++) {
			if($s1[$i] == $s2[$j]) $count++;
		}
		if($count != 1) return false;
	}
	return true;
}

for($i = 102; ; $i++) {
	$s1 = strval($i);
	if($s1[0] != '1') continue;

	$found = true;
	for($x = 2; $x <= 6; $x++) {
		if(!same($s1, strval($i * $x))) {
			$found = false;
			break;
		}
	}

	if($found) {
		print $i;
        break;
	}
}

?>
