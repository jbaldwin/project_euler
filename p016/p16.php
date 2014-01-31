<?php

/**
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
**/

$two = gmp_init("2");
$power = 1000;
$result = gmp_pow($two, $power);

$strval = gmp_strval($result);
$sum = gmp_init("0");
for($i = 0; $i < strlen($strval); $i++) {
	$sum = gmp_add($sum, $strval[$i]);
}

print gmp_strval($sum);

?>
