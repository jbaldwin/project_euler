<?php

/**
10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001st prime number?
**/

require_once "../lib/prime.php";

$stop = 10001;
$count = 1; // count '2' already
$prime = 1;

do {
	$prime += 2;
	if(is_prime($prime)) {
		$count++;
	}
} while($count < $stop);

print $prime;

?>
