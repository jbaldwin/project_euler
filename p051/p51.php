<?php

/**
Prime digit replacements

By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values:
13, 23, 43, 53, 74, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example
having seven primes among the generated numbers, yielding the family: 56003, 56113, 56333, 564433, 56663,
56773, and 569933.  Consequently 56003, being the first member of this family, is the smallest prime with
this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the
same digit, is part of an eight prime value famly.
**/

require_once "../lib/prime.php";

$limit = 1000000;
$primesieve = prime_sieve($limit);
$primekeys = array();
foreach($primesieve as $prime) {
	$primekeys[$prime] = true;
}

for($i = 0; $i < count($primesieve); $i++) {

	$sorig = strval($primesieve[$i]);
	$len = strlen($sorig);
	if($len < 4) continue;

	$primes = array(0,0,0,0,0,0,0,0,0,0);

	for($c1 = 0; $c1 < $len; $c1++) {
	for($c2 = 1; $c2 < $len; $c2++) {
	for($c3 = 2; $c3 < $len; $c3++) {

		if($c1 == $c2 || $c1 == $c3 || $c2 == $c3) continue;

		$s = $sorig;
		$count = 0;
		
		for($r = 0; $r < 10; $r++) {
			if($c1 == 0 && $r == 0) continue;
			$s[$c1] = $s[$c2] = $s[$c3] = $r;
			if(array_key_exists(intval($s), $primekeys)) {
			//if($sieve[prime_sieve_index(intval($s))] == true) {
				$count++;
				$primes[$r] = intval($s);
			} else {
				$primes[$r] = 0;
			}
		}

		if($count == 8) {
			print $sorig . "\n\n";

			foreach($primes as $v) {
				if($v != 0) {
					print $v . "\n";
				}
			} 

			die();
		}
	}
	}
	}
}

?>

