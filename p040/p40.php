<?php

/**
Champernowne's constant

An irrational decimal fraction is created by concatenating the positive integers:

	0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

	d_1 x d_10 x d_100 x d_1000 x d_10000 x d_100000 x d_1000000
**/

$s = "";
$i = 1;
while(strlen($s) < 1000000) {
	$s .= strval($i);
	$i++;
}

$d_1 = $s[0];
$d_2 = $s[9];
$d_3 = $s[99];
$d_4 = $s[999];
$d_5 = $s[9999];
$d_6 = $s[99999];
$d_7 = $s[999999];

print $d_1 . " " . $d_2 . " " . $d_3 . " " . $d_4 . " " . $d_5 . " " . $d_6 . " " . $d_7 . "\n";

$r = $d_1 * $d_2 * $d_3 * $d_4 * $d_5 * $d_6 * $d_7;

print $r . "\n";

?>

