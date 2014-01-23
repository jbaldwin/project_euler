<?php

require_once "../lib/division.php";

$triangle = 0;
$i = 1;

while(num_divisors($triangle) < 500) {
	$triangle += $i;
	$i++;
}

print $triangle;

?>
