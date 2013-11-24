<?php

$results = array();

function lattice_paths($x, $y) {
	if($x == 0 && $y == 0) return 1;

	// check if the result has already been computed.
	global $results;
	if(array_key_exists($x, $results)) {
		$inner = $results[$x];
		if(array_key_exists($y, $inner)) {
			return $inner[$y];
		}
	}

	$total = 0;
	if($x > 0) $total += lattice_paths($x - 1, $y);
	if($y > 0) $total += lattice_paths($x, $y - 1);

	// save result, and flip result [$y][$x]
	if(!array_key_exists($x, $results)) {
		$results[$x] = array();
	}
	if(!array_key_exists($y, $results)) {
		$results[$y] = array();
	}
	$results[$x][$y] = $total;
	$results[$y][$x] = $total;

	return $total;
}

print lattice_paths($argv[1], $argv[1]) . "\n";


?>


