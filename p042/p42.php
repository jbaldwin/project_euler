<?php

/**
The nth term of the sequence of triangle numbers is given by, t_n = (1/2)n(n+1); so the first ten 
triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding
these values we form a word value.  For example, the word value for SKY is 19 + 11 + 25 = 55 = t_10.
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt, a 16K text file containing nearly two-thousand common English words, how many
are triangle words?
**/

$l2i = array();
for($i = "A", $j = 1; $i <= "Z"; $i++, $j++) {
	$l2i[$i] = $j;
}

$raw = file_get_contents("words.txt");
$raw = str_replace('"', '', $raw);
$words = explode(",", $raw);

$limit = 19; // no triangles are composed of higher than triangle(19) in words.txt
$triangles = array();
for($i = 1; $i < $limit; $i++) {
	$t = (1/2) * $i * ($i + 1);
	$triangles[$t] = $t;
}


$triangle_words = 0;
foreach($words as $word) {
	$len = strlen($word);
	$total = 0;
	for($i = 0; $i < $len; $i++) {
		if(array_key_exists($word[$i], $l2i)) {
			$total += $l2i[$word[$i]];
		}
	}

	if(array_key_exists($total, $triangles)) {
		$triangle_words++;
	}
}

print $triangle_words;

?>
