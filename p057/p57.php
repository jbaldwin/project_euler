<?php

/**
Square root convergents

It is possible to show that the square root of two can be expressed as an infinite continued fraction.

	sqrt(2) = 1 + 1/ (2 + 1/ (2 + 1/ (2 + ... ))) = 1.414214...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expasions are 99/70, 239/169, and 577/408, but the eight expansion, 1392/985, is the first
example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
**/

// numerator   is 2 * (n - 1) + (n - 2)
// denominator is 2 * (d - 1) + (d - 2)

$fractions = array(
	array("1", "1"),
    array("3", "2")
);

$count = 0;
for($i = 2; $i <= 1000; $i++) {

	$n = bcadd(bcmul($fractions[$i - 1][0], "2"), $fractions[$i - 2][0]);
	$d = bcadd(bcmul($fractions[$i - 1][1], "2"), $fractions[$i - 2][1]);
	$fractions[$i] = array($n, $d);

	if(strlen($n) > strlen($d)) {
		$count++;
	}
}

print $count;
