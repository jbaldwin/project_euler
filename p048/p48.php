<?php

/**
Self powers

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
**/

$sum = gmp_init("0");
for($i = 1; $i <= 1000; $i++) {
	$sum = gmp_add($sum, gmp_pow(strval($i), $i));
}

print substr(gmp_strval($sum), -10) . "\n";

?>

