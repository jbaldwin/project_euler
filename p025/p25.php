<?php

/**
The Fibonacci sequence is defined by the recurrence relation:

F_n = F_n-1 + F_n-2, where F_1 = 1 and F_2 = 1.

Hence the first 12 terms will be:

F_1  =   1
F_2  =   1
F_3  =   2
F_4  =   3
F_5  =   5
F_6  =   8
F_7  =  13
F_8  =  21
F_9  =  34
F_10 =  55
F_11 =  89
F_12 = 144
**/

$length = 1000;
$n  = gmp_init("1");
$n1 = gmp_init("1");
$term = 2;
$found = false;

while(!$found) {
	$t = gmp_add($n, $n1);
	$n1 = $n;
	$n = $t;

	$str = gmp_strval($n);
	if(strlen($str) >= $length) {
		$found = true;
	} 
	$term++;
}

print gmp_strval($n) . "\n";
print $term . "\n";

?>
