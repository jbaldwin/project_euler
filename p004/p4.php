<?php

/**
Largest palindrome product

A palindromic number reads the same both ways.  The largest palindrome made from the product of two 2-digit
numbers is 9009 = 91 x99.
Find the largest palindrome made from the product of two 3-digit numbers.
**/

function is_palindrome($letters) {
	return strrev($letters) == $letters;
}

$max = 0;
for($i = 100; $i <= 999; $i++) {
	for($j = $i; $j <= 999; $j++) {
		if(is_palindrome(strval($i * $j))) {
			$max = max($max, $i * $j);
		}
	}
}

print $max . "\n";

?>
