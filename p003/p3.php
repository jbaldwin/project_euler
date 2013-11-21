<?php

/**
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
**/

$magic = 600851475143;

function isPrime($x) {
	if($x == 1) return false;
	if($x < 4) return true;
	if($x % 2 == 0) return false;
	if($x < 9) return true;
	if($x % 3 == 0) return false;

	$r = floor(sqrt($x));
	$f = 5;
	while($f <= $r) {
		if($x % $f == 0) return false;
		if($x % ($f + 2) == 0) return false;
		$f += 6;
	}
	return true;
}

function isFactor($x) {
	return ($GLOBALS['magic'] % $x == 0) ? true : false;
}


echo $magic . " is the magic number.\n";

$primes = array();

$curr = $magic;
$found = false;
$sqrt = floor(sqrt($magic));

while(!$found) {

	if($curr % 2 == 0) {
		echo "2 is a prime factor.\n";
		array_push($primes, $i);
		$curr /= $i;
		goto skip;
	}

	// find the next highest prime number
	for($i = 3; $i < $sqrt; $i += 2) {
		if(isPrime($i)) {
			// now see if the current number can be divided by it
			if($curr % $i == 0) {
				echo $i . " is a prime factor.\n";
				array_push($primes, $i);
				$curr /= $i;
				break;
			}

		}
	}

skip:
	if(isPrime($curr)) {
		array_push($primes, $curr);
		echo $curr . " is a prime factor.\n";
		$found = true;
	}

}

$max = 0;
foreach($primes as $prime) {
	$max = max($max, $prime);
}

echo $max . " is the maximum prime factor of " . $magic . ".\n";

?>

