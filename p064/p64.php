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
*   a_2 = 3, 2 / (sqrt(23) - 3) = 
*
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

/**
This is how I figured out the algorithm works.
By analyzing the given examples one can find out that
a0 is the floor of the sqrt(n).  (this took me a while to recognize)
As sqrt(23) ~= 4.7, so naturally a0 = 4.
Now you can repeat by keeping the remainder and taking floor(1 / r_i)
to get the next number in the sqrt period.  (I initially missed this as
you can see below I had 1 / (sqrt($n) - $a0) which is still correct
but makes for a longer algo...)

$n = 23;
$a0 = floor(sqrt($n));

$r1 = 1 / (sqrt($n) - $a0);
$a1 = floor($r1);
$r1 = $r1 - $a1;

$r2 = 1 / $r1;
$a2 = floor($r2);
$r2 = $r2 - $a2;

$r3 = 1 / $r2;
$a3 = floor($r3);
$r3 = $r3 - $a3;

$r4 = 1 / $r3;
$a4 = floor($r4);
$r4 = $r4 - $a4;

print "[" . $a0 . ";(" . $a1 . "," . $a2 . "," . $a3 . "," . $a4 .  ")]\n";
print $r1 . "," . $r2 . "," . $r3 . "," . $r4;
**/

$stdin = fopen("php://stdin", "r");

function sqrt_period($n, $scale, $chop) {
	bcscale($scale + $chop);

	$a = array();	// "a" values
	$r = array();	// remainders

	$t_0 = bcsqrt($n);
	$a_0 = $t_0[0];
	$r_i = bcsub($t_0, $a_0);	// a_0 value is not counted

//	print $a_0 . ", " . $r_i . "\n";

	while(true) {
		$t_i = bcdiv("1", $r_i);
		$a_i = $t_i[0];
		$r_i = bcsub($t_i, $a_i);

		// chop off the last X digits... they are not always perfect
		$key = substr($r_i, 0, -$chop);
		if(array_key_exists($key, $r)) {
			break;
		}
		if(count($a) >= 1000) return -1;	// hmm..?

		$a[] = $a_i;
		$r[$key] = true;

//		print $a_i . ", " . $key . "\n";
	}

	return count($a);
}

$count = 0;
for($i = 2; $i <= 10000; $i++) {

	$sqrt = bcsqrt(strval($i));
	$squared = bcmul($sqrt, $sqrt);
	if(bccomp(strval($i), $squared) == 0) {
		continue;	// not irrational
	}

	$scale = 32;
	$chop = 8;

retry:
	$period = sqrt_period($i, $scale, $chop);
	if($period == -1) {
		print "exhausted 1000 at scale=" . $scale . " and chop=" . $chop . "\n";
		$scale *= 2;
		$chop *= 2;
		goto retry;
	}

	if($period % 2 == 1) $count++;
	print $i . " period=" . $period . "\n";
//	$line = fgets($stdin);
}

print $count;

?>
