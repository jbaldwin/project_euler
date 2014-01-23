<?php

/**
Sum square difference

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
3025 - 385 = 2640.
Find the difference between the sum of squares of the first one hundred natural numbers and the square of the sum.
**/

$square_of_sum = 0;
$sum_of_square = 0;
for($i = 1; $i <= 100; $i++) {
	$square_of_sum += $i;
	$sum_of_square += pow($i, 2);
}
$square_of_sum = pow($square_of_sum, 2);
print $square_of_sum - $sum_of_square . "\n";

?>
