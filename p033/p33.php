<?php

/**
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify
it may incorrectly believe that 49/98 = 4/8, which is correct, it obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trival examples of this type of fraction, less than one in value, and 
containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest commo terms, find the value of the denominator.
**/

$fractions = array();

for($n = 10; $n <= 99; $n++) {
	for($d = 10; $d <= 99; $d++) {
		if($n >= $d) continue;

		$n_str = strval($n);
		$d_str = strval($d);

		// find the pattern of ab/bc where c != 0 and a != c
		// and n > d (fraction must be less than 1)
		if($n_str[1] == $d_str[0] &&
		   $n_str[0] != $d_str[1] && 
		   $d_str[1] != "0") {
			$n1 = $n_str[0];
			$d1 = $d_str[1];
			if(intval($n1) / intval($d1) == $n / $d) {
				print $n . "/" . $d . " = " . $n / $d .  "\n";
				array_push($fractions, array($n, $d));
			}
		}
	}
}

$numerator = 1;
$denominator = 1;

// find the product of the fractions
foreach($fractions as $f) {
	$n = $f[0];
	$d = $f[1];

	$numerator *= $n;
	$denominator *= $d;
}

// reduce the fraction
for($i = $numerator; $i >= 1; $i--) {
	if($numerator % $i == 0 &&
	   $denominator % $i == 0) {
		$numerator /= $i;
		$denominator /= $i;
		break;
	}
}

print $numerator . "/" . $denominator . " = " . $numerator / $denominator . "\n";

?>

