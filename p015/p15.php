<?php

/**
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

<images not shown>

How many such routes are there through a 20x20 grid?
**/

/**
function lattice_paths($x, $y) {
	if($x == 0 && $y == 0) return 1;

	$total = 0;
	if($x > 0) $total += lattice_paths($x - 1, $y);
	if($y > 0) $total += lattice_paths($x, $y - 1);
	return $total;
}

print lattice_paths($argv[1], $argv[1]) . "\n";
**/

print exec("php -f p15.combinations.php 20");

?>
