<?php

/**
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
**/

require_once "../lib/prime.php";

$limit = 2000000;
$sum = 2;
for($i = 3; $i <= $limit; $i += 2 ) {
	if(is_prime($i)) {
		$sum += $i;
	}
}

print $sum . "\n";

?>

