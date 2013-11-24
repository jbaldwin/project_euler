<?php

/**
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are
3 + 3 + 5 + 4 +4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how
many letters would be used?

NOTE: Do not count spaces or hyphens.  For example, 342 (three hundred and forty-two) contains
23 letters and 115 (one hundred and fifteen) contains 20 letters.  The use of "and" when writing 
out numbers is in compliane with British usage.
**/

$ones = array(
	0 => "", // zero is not inclusive and does not appear like -> "forty-zero"
	1 => "one",
	2 => "two",
	3 => "three",
	4 => "four",
	5 => "five",
	6 => "six",
	7 => "seven",
	8 => "eight",
	9 => "nine",	
);

$tens = array(
	0 => "",
	1 => array(
		0 => "ten",
		1 => "eleven",
		2 => "twelve",
		3 => "thirteen",
		4 => "fourteen",
		5 => "fifteen",
		6 => "sixteen",
		7 => "seventeen",
		8 => "eighteen",
		9 => "nineteen"
	),
	2 => "twenty",
	3 => "thirty",
	4 => "forty",
	5 => "fifty",
	6 => "sixty",
	7 => "seventy",
	8 => "eighty",
	9 => "ninety"
);

// hundreds are the same as ones + "hundred" and potentially "and".

$allwords = "";

for($i = 1; $i <= 1000; $i++) {
	$s = strval($i);

	$len = strlen($s);

	if($len == 1) {
		$allwords .= " " .  $ones[$s];
	}

	if($len == 2) {
		// handle special 1x case
		if($s[0] == 1) {
			$allwords .= " " . $tens[1][$s[1]];
		} else {
			$allwords .= " " . $tens[$s[0]] . " " . $ones[$s[1]];
		}
	}

	if($len == 3) {
		// add hundreds place
		$allwords .= " " . $ones[$s[0]] . " hundred";
		if($s[1] != "0" || $s[2] != "0") {
			$allwords .= " and";
		}

		if($s[1] == 1) {
			$allwords .= " " . $tens[1][$s[2]];
		} else {
			$allwords .= " " . $tens[$s[1]] . " " . $ones[$s[2]];
		}
	}

	if($len == 4) {
		$allwords .= "one thousand";
	}

	$allwords .= "\n";

}

print $allwords . "\n";
$allwords = str_replace(array("\n", " "), "", $allwords); 
print strlen($allwords) . " total letters.\n";

?>

