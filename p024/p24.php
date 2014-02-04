<?php

/**
A permutation is an ordered arrangement of objects.  For example, 3124 is one possible permutation of the
digits 1, 2, 3 and 4.  If all of the permutations are listed numerically or alphabetically, we call it
lexicographic order.  The lexicographic permutations of 0, 1, 2 are:

012	021	102	120	201	210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
**/

function factorial($n) {
	$total = 1;

	if($n <= 1) return 1;
	for($i = $n; $i > 0; $i--) {
		$total *= $i;
	}

	return $total;
}

function lexicographic_index($p) {
	$result = 0;

	for($j = 0; $j < count($p); $j++) {
		$k = 0;
		for($i = $j + 1; $i < count($p); $i++) {
			if($p[$i] < $p[$j]) {
				$k += 1;
			}
		}

		$result += $k * factorial(count($p) - $j - 1);
	}

	return $result;
}

function lexicographic_followers($p) {
	return factorial(count($p)) - lexicographic_index($p) - 1;
}

function print_perm($p) {
	for($i = 0; $i < count($p); $i++) {
		print $p[$i];
	}
}

$limit = 1000000;
$p = array(0,0,0,0,0,0,0,0,0,0);
$nums = array(0,1,2,3,4,5,6,7,8,9);

for($i = 0; $i < count($p); $i++) {

	// determine the next maximum number for the next slot in the permutation
	// go through the remaining available numbers
	// append the 
	$max = -1;
	$max_index = -1;
	for($j = 0; $j < count($nums); $j++) {
		$p[$i] = $nums[$j];
		for($k = 0; $k < count($nums); $k++) {
			if(!in_array($nums[$k], $p) && $i + $k + 1 < count($p)) {
				$p[$i + $k + 1] = $nums[$k];
			}
		}
		$t = lexicographic_index($p);

		if($t >= $limit) continue;
		if($t > $max) {
			$max = $t;
			$max_index = $j;
		}
	}

	$p[$i] = $nums[$max_index];
	array_splice($nums, $max_index, 1);
}

print_perm($p);

// answer determined by manually checking hightest to lowest numbers, the algorithm
// above does the same but automated
//print lexicographic_index(array(2,7,8,3,9,1,5,4,6,0)) . "\n";

?>
