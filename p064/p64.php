<?php

function is_perfect_square($n) {
	$sqrt = sqrt($n);
	return ($sqrt == floor($sqrt)) ? true : false;
}

function sqrt_period($n) {
	$a = floor(sqrt($n));
	
	$a0 = $a;
	$m = 0;
	$d = 1;

	$period = 0;
	while($a != $a0 * 2) {
		$period++;
		$m = $d * $a - $m;
		$d = ($n - $m * $m) / $d;
		$a = floor(($a0 + $m) / $d);
	}
	return $period;
}

$count = 0;
for($n = 2; $n <= 10000; $n++) {
	if(is_perfect_square($n)) {
		continue;
	}

	$period = sqrt_period($n);

	if($period % 2 == 1) $count++;
}

print $count;
?>
