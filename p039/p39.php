<?php

/**
If p is the perimeter of a right angle triangle with integral length sides {a,b,c}, there are exactly 
three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?
**/

// A pythagorean triple is a right triangle where a^2 + b^2 = c^2

$max_p = 0;
$max_c = 0;

for($p = 3; $p <= 1000; $p++) {
	$count = 0;
	for($a = 1; $a < $p; $a++) {
	for($b = $a; $b < $p; $b++) {
		$c = $p - $a - $b;

		if($a + $b <= $c) continue;
		if($c <= 0) continue;

		if($c * $c == $a * $a + $b * $b) {
			$count++;
		}
	}
	}
	if($count > $max_c) {
		$max_p = $p;
		$max_c = $count;
	}
}

print "\n" . $max_p . " " . $max_c . "\n" 

?>

