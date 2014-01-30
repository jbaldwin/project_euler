<?php

/**
* Odd period square roots
*
* All square roots are periodic when written as continued fractions and can be
* written in the form:
*
* sqrt(n) = a_0 + (1 / a_1 + (1 / (a_2 + (1 / a_3 + ... ))))
*
* For example, let us consider sqrt(23):
*   sqrt(23) = 4 + sqrt(23) - 4 = 4 + (1 / 1 / (sqrt(23) - 4)) = 4 + (1 / (1 + (sqrt(23) 3) / 7))
*
* If we continue we would get the following expansion:
*   sqrt(23) = 4 + (1 / (1 + (1 / (3 + (1 / (1 + (1 / 8 + ...)))))))
*
* The process can be summarised as follows:
*   a_0 = 4, 1 / (sqrt(23) - 4) = (sqrt(23) + 4) / 7 = 1 + ((sqrt(23) - 3) / 7)
*   a_1 = 1, 7 / (sqrt(23) - 3) = (7 * sqrt(23) + 3) / 14 = 3 + ((sqrt(23) - 3) / 2)
*   a_2 = 3, 2 / (sqrt(23) - 3) = (2 * sqrt(23) + 3) / 14 = 1 + ((sqrt(23) - 4) / 7)
*   a_3 = 1, 7 / (sqrt(23) - 4) = (7 * sqrt(23) + 4) / 7 = 8 + sqrt(23) - 4
*   a_4 = 8, 1 / (sqrt(23) - 4) = (sqrt(23) + 4) / 7 = 1 + ((sqrt(23) - 3) / 7)
*   a_5 = 1, 7 / (sqrt(23) - 3) = (7 * sqrt(23) + 3) / 14 = 3 + ((sqrt(23) - 3) / 2)
*   a_6 = 3, 2 / (sqrt(23) - 3) = (2 * sqrt(23) + 3) / 14 = 1 + ((sqrt(23) - 4) / 7)
*   a_7 = 1, 7 / (sqrt(23) - 4) = (7 * sqrt(23) + 4) / 7 = 8 + sqrt(23) - 4
*
* It can be seen that the sequence is repeating.  For conciseness, we use the notation
* sqrt(23) = [4;(1,3,1,8)], to indicate that the block (1,3,1,8) repeats indefinitely.
*
* The first ten continued fraction representations of (irrational) square roots are:
*   sqrt(2)  = [1;(2)], period = 1
*   sqrt(3)  = [1;(1,2)], period = 2
*   sqrt(5)  = [2;(4)], period = 1
*   sqrt(6)  = [2;(2,4)], period = 2
*   sqrt(7)  = [2;(1,1,1,4)], period = 4
*   sqrt(8)  = [2;(1,4)], period = 2
*   sqrt(10) = [3;(6)], period = 1
*   sqrt(11) = [3;(3,6)], period = 2
*   sqrt(12) = [3;(2,6)], period = 2
*   sqrt(13) = [3;(1,1,1,1,6)], period = 5
*
* Exactly four continued fractions, for N <= 13, have an odd period.
*
* How many continued fractions for N <= 10000 have an odd period?
**/

function sqrt_period($n) {
	// 32 and 64 produces 1 off error 1323 instead of 1322...
	// so there is a percision error below at 32~ for 1 sqrt
	$scale = 64;
	$chop = 128;

	$found = false;
	while(!$found) {

		bcscale($scale + $chop);

		$a = array();	// "a" values
		$r = array();	// remainders

		$t_0 = bcsqrt($n);
		$a_0 = substr($t_0, 0, strpos($t_0, "."));
		$r_i = bcsub($t_0, $a_0);	// a_0 value is not counted

		while(true) {
			$t_i = bcdiv("1", $r_i);
			$a_i = substr($t_i, 0, strpos($t_i, "."));
			$r_i = bcsub($t_i, $a_i);

			// Chop off the last X digits... they are not always perfect
			// If the remainder key already exists then the period has
			// been found so stop
			$key = substr($r_i, 0, -$chop);
			if(array_key_exists($key, $r)) {
				$found = true;
				break;
			}
			
			// 217 is the longest chain so try again 
			// with a higher scale and chop
			if(count($a) >= 250) {
				$scale *= 2;
				$chop *= 2;
				break;
			}

			$a[] = $a_i;
			$r[$key] = true;
		}
	}

	return count($a);
}

function is_perfect_square($n) {
	$sqrt = bcsqrt(strval($n), 16);	// Scale 16 is enough
	$squared = bcmul($sqrt, $sqrt);
	return (bccomp(strval($n), $squared) == 0) ? true : false;
}

$count = 0;
for($n = 2; $n <= 10000; $n++) {
	if(is_perfect_square($n)) continue;
	$period = sqrt_period($n);

	if($period % 2 == 1) $count++;
}

print $count;
?>
