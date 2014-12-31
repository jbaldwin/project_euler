<?php

/**
Triangular, pentagonal, and hexagonal

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle	T_n = n(n+1)/2		1, 3, 6, 10, 15, ...
Pentagonal	P_n = n(3n-1)/2		1, 5, 12, 22, 35, ...
Hexagonal	H_n = n(2n-1)		1, 6, 15, 28, 45, ...

It can be verified that T_285 = P_165 = H_143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
**/

function triangle($n) {
	return $n * ($n + 1) / 2;
}

function pentagonal($n) {
	return $n * (3 * $n - 1) / 2;
}

function hexagonal($n) {
	return $n * (2 * $n - 1);
}

$t = 286;
$p = 165;
$h = 143;

$tval = triangle($t);
$pval = pentagonal($p);
$hval = hexagonal($h);

$found = false;

while(!$found) {
	while($hval < $pval) {
		$h++;
		$hval = hexagonal($h);
	}

	while($pval < $tval) {
		$p++;
		$pval = pentagonal($p);
	}

	if($tval == $pval && $tval == $hval) {
		$found = true;
	} else {
		$t++;
		$tval = triangle($t);
	}
}

print $tval;

?>
