<?php

/**
A permutation is an ordered arrangement of objects.  For example, 3124 is one possible permutation of the
digits 1, 2, 3 and 4.  If all of the permutations are listed numerically or alphabetically, we call it
lexicographic order.  The lexicographic permutations of 0, 1, 2 are:

012	021	102	120	201	210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
**/

ini_set('memory_limit', '2048M');


$permutations = array();

function perms($numbers, $rest)  {
	global $permutations;

	if(strlen($rest) == 0) {
		array_push($permutations,  $numbers);
		if(count($permutations) % 10000 == 0) print count($permutations) . "\n";
	} else {
		for($i = 0; $i < strlen($rest); $i++) {
			perms($numbers . $rest[$i], str_replace($rest[$i], "", $rest));
		}
	}
}


$limit = 1000000;
$numbers = '0123456789';
//$numbers = '012';
perms("", $numbers);
//sort($perms, SORT_NUMERIC);
//$perms = &array_unique($perms);


print count($permutations) . "\n";
//var_dump($permutations);

print $permutations[$limit] . "\n";

?>

