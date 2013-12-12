<?php

/**
A unit fraction contains 1 in the numerator.  The decimal representation of the unit fractions
with denomiators 2 to 10 are given:

1/2  = 0.5
1/3  = 0.(3)
1/4  = 0.25
1/5  = 0.2
1/6  = 0.1(6)
1/7  = 0.(142857)
1/8  = 0.125
1/9  = 0.(1)
1/10 = 0.1

Where 0.1(6) means 0.166666...., and has a 1-digit recurring cycle.  It can be seen that 1/7 has a 
6-digit recurring cycle.

Find the value of d < 1000 for which 1 / d contains the longest recurring cycle in its decimal fraction part.
**/

function generate_fractions($numbers, $precision) {
	$numerator = "1";
	$fractions = array();
	foreach($numbers as $number) {
		$f = bcdiv($numerator, strval($number), $precision);
		$fractions[$number] = $f;
	}
	return $fractions;
}


function strip_leading_zeros($fractions) {
	// strip leading 0.0000 etc...
	foreach($fractions as $k => $v) {
		for($i = 0; $i < strlen($v); $i++) {
			if($v[$i] != '0' && $v[$i] != '.') {
				$fractions[$k] = substr($v, $i);
				break;
			}
		}
	}
	return $fractions;
}

function remove_one_length_fractions($fractions) {
	// remove all '1' length repeaters
	foreach($fractions as $k => $v) {
		$len = strlen($v);
		$same = 0;
		for($i = $len - 2; $i >= 0; $i--) {
			if($v[$i] == $v[$len - 1]) $same++;
		}
		if($same >= $len / 2) {
			unset($fractions[$k]);
		}
	}
	return $fractions;
}

function remove_two_length_fractions($fractions) {

	foreach($fractions as $k => $v) {
		$len = strlen($v);
		$same = 0;
		for($i = $len - 4; $i >= 2; $i -= 2) {
			if($v[$i] == $v[$len - 2] &&
				$v[$i + 1] == $v[$len -1]) {
				$same++;
			}
		}
		if($same >= $len / 4) {
			unset($fractions[$k]);
		}
	}

	return $fractions;
}

function iterate($fractions) {

	$results = array();
	
	foreach($fractions as $k => $v) {
	
		$patterns = array();
		// increment $p across the string where $l is increased to find a pattern
		for($p = 0; $p < strlen($v); $p++) {
			// increment the length of the repetition we are searching for, the repetition
			// can be no longer than half of the remaining string length
			for($l = 1; $l < (strlen($v) - $p) / 4; $l++) {
	
				$pattern = "";
				for($i = 0; $i < $l; $i++) {
					// if any char in the sequence doesn't match
					// stop..
					if($v[$p + $i] != $v[$p + $l + $i]) {
						goto not_found;
					}
					$pattern .= $v[$p + $l + $i];
				}
				// found a pattern, make sure it repeats to the end
				if(strlen($pattern) != 0) {
					for($i = $p + $l; $p + $l + $i < strlen($v); $i += $l) {
						for($j = 0; $j < $l; $j++) {
							// stopped repeating
							if($v[$p + $j] != $v[$p + $i + $j]) {
								goto not_found;
							}
						}
					}
					array_push($patterns, $pattern);
				}
				not_found:
			}
	
		}
	
		// now check each pattern and see if longer patterns are simply repititions
		// of a smaller pattern
		for($i = 0; $i < count($patterns); $i++) {
			$i_len = strlen($patterns[$i]);
			for($j = $i + 1; $j < count($patterns); $j++) {
				$j_len = strlen($patterns[$j]);
	
				if($j_len == 0 || $i_len == 0) continue;
	
				// if the strings match after the smaller one is repeated
				// then remove it from the pool since it is a duplicate
				if($j_len < $i_len) {
					if($i_len % $j_len == 0) {
						$s = str_repeat($patterns[$j], ($i_len / $j_len));
						if($s == $patterns[$i]) {
							$patterns[$i] = "";
						}
					}
				} else {
					if($j_len % $i_len == 0) {
						$s = str_repeat($patterns[$i], ($j_len / $i_len));
						if($s == $patterns[$j]) {
							$patterns[$j] = "";
						}
					}
				}
			}
		}
	
		$pattern = "";
		$max = 0;
		foreach($patterns as $p) {
			$len = strlen($p);
			if($len > $max) {
				$max = $len;
				$pattern = $p;
			}
		}

		print $k . " repeat len = " . $max . "\n";
		
	
		//print "1 / " . $k . " = " . $v . " with repeat length of " . $max . "\npattern=" . $pattern . "\n";
	
		$results[$k] = $pattern;
//		array_push($results, array($k, $max));
	
	}
	return $results;
}

/*$output = "";
foreach($results as $r) {
	if($r[1] >= 50) {
		$output .= $r[0] . " " . $r[1] . "\n";
	}
}
file_put_contents("output.txt", $output);*/

// start with 64 numbers precision and increment up discarding all 
// numbers that have greater than 2 in length but not the maximum
// length 
$precision = 64;
$numbers = array();
for($i = 2; $i < 1000; $i++) {
	$numbers[$i] = $i;
}

$max = -1;
$max_index = -1;

$stdin = fopen('php://stdin', 'r');

// iterate until there is only one item left!
while(count($numbers) > 1) {
	// generate the new precision fractions
	$fractions = generate_fractions($numbers, $precision);
	$fractions = strip_leading_zeros($fractions);
	$fractions = remove_one_length_fractions($fractions);
	$fractions = remove_two_length_fractions($fractions);
	$results = iterate($fractions);


	// check the length of each
	foreach($results as $k => $v) {
		$len = strlen($v);
		// save a new maximum has been found
		if($len > $max) {
			// remove the old maximum
			if(array_key_exists($max_index, $results)) {
				unset($results[$max_index]);
			}
			$max = $len;
			$max_index = $k;
			print $k . " has been eliminated with repeat length = " . $len . "\n";
		// has length to it but it is not longer than a previous maximum, discard
		// but do not remove the maximum found item yet... (just in case)
		} else if($len >= 3 && $k != $max_index) {
			unset($results[$k]);
			print $k . " has been eliminated with repeat length = " . $len . "\n";
		}
	}
	// reset numbers array and only generate fractions for the remaining items that no
	// pattern was found for the current precision
	$numbers = array();
	foreach($results as $k => $v) {
		$numbers[$k] = $k;
	}
	// double the precision each time to quickly weed out bad numbers
	$precision *= 2;
	print "precision=" . $precision . "\n";
	print count($numbers) . " remanaining numbers to check\n";
	print "max number=" . $max_index . " max_len=" . $max . "\n";
	$line = fgets($stdin);
}

?>

