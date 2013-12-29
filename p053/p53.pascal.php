<?php

/**
Calculated using pascal's triangle.
**/

$triangle = array();
for($a = 0; $a <= 100; $a++) {
	$triangle[$a] = array();
	$triangle[$a][0] = 1;
	$triangle[$a][$a] = 1;
}
$c = 0;
for($x = 1; $x <= 100; $x++) {
	for($y = 1; $y <= $x - 1; $y++) {
		$triangle[$x][$y] = $triangle[$x - 1][$y] + $triangle[$x - 1][$y - 1];
		if($triangle[$x][$y] > 1000000) {
			$c++;
		}
	}
}

print $c . "\n";

?>

