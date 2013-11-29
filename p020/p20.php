<?php

/**
n! means n * (n - 1) * ... 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
**/

$onehundred = gmp_fact(100);
$str_val = gmp_strval($onehundred);

$total = 0;
for($i = 0; $i < strlen($str_val); $i++) {
	$total += $str_val[$i];
}

print $total . "\n";

?>

