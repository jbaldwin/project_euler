<?php

/**
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 sprial is formed
as follows:

21	22	23	24	25
20	7	8	9	10
19	6	1	2	11
18	5	4	3	12
17	6	15	14	13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
**/

$limit = 1001 * 1001;

// The strategy here is to count the corners of each succesive ring around the center.
// This implies each square ring has 4 corners to be added.
// It can also be noticed that each corner is always an odd integer.
// It can also be noticed that each ring skips an additional odd number on each side,
// see the example on the outer most ring it skips 15, 19, 23, and 11 -- all odds
// but they are not counted since they are not corners.

$skip = 0;	// how many square "rings" from the center, and thus how many odds to skip/not count
$total = 1;	// start with 1 already counted, it is the only unconforming 'corner'
$count = 0;	// keeps track of how many corners on a ring have been added to the total,
		// when this hits 4 then increment $skip since a new outer ring is being traversed
for($i = 3; $i <= $limit; $i += 2) {
	
	// skip this many odd numbers for this ring depth
	for($j = 0; $j < $skip; $j++) $i += 2;

	$total += $i;
	$count++;

	// every four additions up the skip amount since a new outer ring of numbers
	// is added
	if($count % 4 == 0) $skip++;
}

print $total;

?>
