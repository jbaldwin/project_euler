<?php

function permutate($str) {
	$permutations = array();
	_permutate("", $str, $permutations);
	return $permutations;
}

function _permutate($prefix, $str, &$permutations) {
	$len = strlen($str);
	if($len == 0) {
		array_push($permutations, $prefix);
	} else {
		for($i = 0; $i < $len; $i++) {
			_permutate($prefix . $str[$i],
				substr($str, 0, $i) . substr($str, $i + 1, $len),
				$permutations);
		}
	}
}

?>
