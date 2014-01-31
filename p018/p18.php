<?php

/**
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total
from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

              75
             95 64
            17 47 82
           18 35 87 10
          20 04 82 47 65
         19 01 23 75 03 34
        88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
      41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by
brute force, and requires a clever method ;o)

**/

$triangle = array(
75,
95, 64,
17, 47, 82,
18, 35, 87, 10,
20, 04, 82, 47, 65,
19, 01, 23, 75, 03, 34,
88, 02, 77, 73, 07, 63, 67,
99, 65, 04, 28, 06, 16, 70, 92,
41, 41, 26, 56, 83, 40, 80, 70, 33,
41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
04, 62, 98, 27, 23, 09, 70, 98, 73, 93, 38, 53, 60, 04, 23,
);

function greedy($triangle, $rows) {
	$i = 0;
	$n = 1;
	$row = 0;
	$max = $triangle[0];
	while($row < $rows) {
		$left = $i + $n;
		$right = $i + $n + 1;

		if($triangle[$left] >= $triangle[$right]) {
			$max += $triangle[$left];
			$i = $left;
		} else {
			$max += $triangle[$right];
			$i = $right;
		}
		$n++;
		$row++;
	}

	return $max;
}

function left($n, $i) {
	return $i + $n;
}
function right($n, $i) {
	return $i + $n + 1;
}

function greedy_two_step($triangle, $rows) {
	$i = 0;
	$n = 1;
	$row = 0;
	$max = $triangle[0];

	$len = count($triangle); 

	while($row < $rows - 1) {

		$left = left($n, $i);
		$right = right($n, $i);

		$leftleft = left($n+1, $left);
		$leftright = right($n+1, $left);

		$rightleft = left($n+1, $right);
		$rightright = right($n+1, $right);

		$n_ll = 0;
		$n_lr = 0;
		$n_rl = 0;
		$n_rr = 0;

		if($left < $len) $n_ll += $triangle[$left];
		if($leftleft < $len) $n_ll += $triangle[$leftleft];

		if($left < $len) $n_lr += $triangle[$left];
		if($leftright < $len) $n_lr += $triangle[$leftright];

		if($right < $len) $n_rl += $triangle[$right];
		if($rightleft < $len) $n_rl += $triangle[$rightleft];

		if($right < $len) $n_rr += $triangle[$right];
		if($rightright < $len) $n_rr += $triangle[$rightright];

		if($n_ll >= $n_lr && $n_ll >= $n_rl && $n_ll >= $n_rr) {
			$i = $left;
			$max += $triangle[$left];
		} else if($n_lr >= $n_ll && $n_lr >= $n_rl && $n_lr >= $n_rr) {
			$i = $left;
			$max += $triangle[$left];
		} else {
			$i = $right;
			$max += $triangle[$right];
		}

		$n++;
		$row++;
	}

	return $max;
}

$greedy_max = greedy_two_step($triangle, 15);

print $greedy_max;

?>
