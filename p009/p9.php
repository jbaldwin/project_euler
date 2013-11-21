<?php

/**
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
**/

for($a = 1; $a < 998; $a++) {
	for($b = 1; $b < 998; $b++) {
		$aa = $a * $a;
		$bb = $b * $b;
		$cc = $aa + $bb;
		$c = sqrt($cc);

		if($a + $b + $c == 1000) {
			print $a . " " . $b . " " . $c . "\n";
			print $a * $b * $c . "\n";
			exit(0);
		}
	}
}

?>

