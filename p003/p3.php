<?php

/**
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
**/

require_once "../lib/prime.php";

$magic = 600851475143;

$factors = prime_factors($magic);
sort($factors, SORT_NUMERIC);
print $factors[count($factors) - 1] . "\n";

?>

