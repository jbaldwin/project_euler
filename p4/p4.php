<?php

/**
A palindromic number reads the same both ways.  The largest palindrome made from the product of two 2-digit
numbers is 9009 = 91 x99.
Find the largest palindrome made from the product of two 3-digit numbers.
**/

function isPalindrome($words) {
	$reverse = strrev($words);
	return (strcmp($words, $reverse) == 0) ? true : false;
}


$max = 0;

for($i = 100; $i <= 999; $i++) {
	for($j = 100; $j <= 999; $j++) {
		if(isPalindrome(strval($i * $j))) {
			$max = max($max, $i * $j);
		}
	}
}

echo "largest palindrome is " . $max . "\n";

?>
