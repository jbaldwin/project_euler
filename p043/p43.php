<?php

/**
Sub-string divisibility

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9
in some order, but it also has a rather interesting sub-string divisibility property.

Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on.  In this way, we not the following:

	* d_2 d_3 d_4 = 406 is divisible by 2
	* d_3 d_4 d_5 = 063 is divisible by 3
	* d_4 d_5 d_6 = 635 is divisible by 5
	* d_5 d_6 d_7 = 357 is divisible by 7
	* d_6 d_7 d_8 = 572 is divisible by 11
	* d_7 d_8 d_9 = 728 is divisible by 13
	* d_8 d_9 d_10= 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
**/

ini_set('memory_limit', '1024M');

$permutations = array();

function permute($prefix, $str) {
	global $permutations;
	$len = strlen($str);
	if($len == 0) {
		if($prefix[0] != '0') {
			array_push($permutations, $prefix);
		}
	} else {
		for($i = 0; $i < $len; $i++) {
			permute($prefix . $str[$i], substr($str, 0, $i) . substr($str, $i + 1, $len));
		}
	}
}

$start = "0123456789";
$divs = array(2,3,5,7,11,13,17);
permute("", $start);
$sum = 0;
foreach($permutations as $p) {
	for($i = 1; $i <= 7; $i++) {
		$d = $p[$i] . $p[$i + 1] . $p[$i + 2];
		if($d % $divs[$i - 1] != 0) {
			goto not_divisible;
		}
	}

	print $p . "\n";
	$sum += $p;

	not_divisible:
}

print "\n" . $sum . "\n";

?>
