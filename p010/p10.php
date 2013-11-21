<?php

/**
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
**/

function isPrime($n) {
	if($n <= 1) return false;
	if($n < 4) return true;
	if($n % 2 == 0) return false;
	if($n < 9) return true;
	if($n % 3 == 0) return false;

	$r = floor(sqrt($n));
	$f = 5;
	while($f <= $r) {
		if($n % $f == 0) return false;
		if($n % ($f + 2) == 0) return false;
		$f += 6;
	}
	return true;
}

$limit = 2000000;
$sum = 2;
for($i = 3; $i <= $limit; $i += 2 ) {
	if(isPrime($i)) {
		$sum += $i;
	}
}

print $sum . "\n";

?>

