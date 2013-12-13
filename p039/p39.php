<?php

/**
If p is the perimeter of a right angle triangle with integral length sides {a,b,c}, there are exactly 
three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?
**/

// A pythagorean triple is a right triangle where a^2 + b^2 = c^2

$results = array();

for($p = 3; $p <= 1000; $p++) {
	for($a = 1; $a < $p; $a++) {
	for($b = $a; $b < $p; $b++) {
		$c = $p - $a - $b;
		if($c <= 0) continue;

		if($c * $c == $a * $a + $b * $b) {

			if(!array_key_exists($p, $results)) {
				$results[$p] = array();
			}

			array_push($results[$p], array($a, $b, $c));

		}
	}
	}
}

$p = 0;
$max = 0;
foreach($results as $k => $r) {
	if(count($r) > $max) {
		$max = count($r);
		$p = $k;
	}

	print $k . " " . count($r) . "\n";
	foreach($r as $triple) {
		print $triple[0] . " " . $triple[1] . " " . $triple[2] . "\n";
	}
}

print "\n" . $p . " " . $max . "\n" 

?>

