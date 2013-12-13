<?php

/**
The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
**/

function is_palindrome($s) {
	$r = strrev($s);
	return ($r == $s);
}

$sum = 0;
for($i = 1; $i < 1000000; $i++) {
	$dec = strval($i);
	$bin = decbin($i);

	if(is_palindrome($dec) &&
	   is_palindrome($bin)) {
		$sum += $i;
		print $dec . " " . $bin . "\n";
	}
}

print $sum . "\n";

?>

