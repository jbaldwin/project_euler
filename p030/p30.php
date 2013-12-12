<?php

/**
1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

**/

$power = 5;
$start = 2;
$end = pow(9, 5) * 6;

$results = array();

for($i = $start; $i <= $end; $i++) {
	$str_i = strval($i);

	$sum_4pow = 0;
	for($j = 0; $j < strlen($str_i); $j++) {
		$sum_4pow += pow($str_i[$j], $power);
	}

	if($sum_4pow == $i) {
		array_push($results, $i);
	}
}

print count($results) . "\n";
$sum = 0;
foreach($results as $r) {
	print $r . "\n";
	$sum += $r;
}
print "sum=" . $sum . "\n";

?>

