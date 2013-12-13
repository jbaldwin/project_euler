<?php

/**
The number 3793 has an interesting property.  Beig prime itself, it is possible to continuously
remove digits from left to right, and remain prime at each state: 3797, 797, 97, 7.  Similarly 
we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

Note: 2, 3, 5, and 7 are not considered to be truncatable primes.
**/
$primes_cache = array();
function is_prime($n) {
	global $primes_cache;

	if(array_key_exists($n, $primes_cache)) return true;

	if(is_prime_cache($n)) {
		$primes_cache[$n] = $n;
		return true;
	}
	return false;
}

function is_prime_cache($n) {
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

function left_trunc($s) {
	$len = strlen($s);
	for($j = 0; $j < $len; $j++) {
		if(!is_prime(intval($s))) return false;
		$s = substr($s, 1);
	}
	return true;
}

function right_trunc($s) {
	$len = strlen($s);
	for($j = 0; $j < $len; $j++) {
		if(!is_prime(intval($s))) return false;
		$s = substr($s, 0, -1);
	}
	return true;
}

function is_trunc_prime($s) {
	// assume $s itself is prime
	return (left_trunc(substr($s, 1)) && right_trunc(substr($s, 0, -1)));
}

$primes = array();
$t_primes = array();
$i = 11;
while(count($t_primes) < 10) {
	if(is_prime($i)) {
		if(is_trunc_prime(strval($i))) {
			array_push($t_primes, $i);
			print $i . "\n";
		}
	}
	$i += 2;
}
// switch algo to find the last truncatable prime by only adding 2/3/5/7

function find_trunc($i) {
	global $t_primes;
	global $front;
	global $back;

	if(count($t_primes) >= 11) return;

	$candidates = array();
	foreach($front as $s) {
		array_push($candidates, $s . $i);
	}
	foreach($back as $s) {
		array_push($candidates, $i . $s);
	}
	foreach($candidates as $c) {
		if(is_prime($c)) {
			//print $c . " is prime.\n";
			if(is_trunc_prime($c)) {
				if(!in_array($c, $t_primes)) {
					array_push($t_primes, $c);
					print $c . "\n";
				}
			}

			find_trunc($c);
		}
	}

}

$front = array(2,3,5,7, 9);
$back = array(3, 5, 7);
find_trunc(2);
find_trunc(3);
find_trunc(5);
find_trunc(7);


$sum = 0;
foreach($t_primes as $t) {
	$sum += $t;
}

print "\n" . $sum . "\n";

?>

