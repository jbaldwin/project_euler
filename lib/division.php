<?php

function num_divisors($n) {
	$divisors = 0;
	$sqrt = floor(sqrt($n));
	for($i = 1; $i <= $sqrt; $i++) {
		if($n % $i == 0) {
			$divisors += 2;
		}
	}

	if($sqrt * $sqrt == $n) $divisors--;

	return $divisors;
}

?>
