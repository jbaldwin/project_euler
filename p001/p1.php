<?php

/**
Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.

Find the sum of all multiples of 3 or 5 below 1000.
**/

function multiple($r, $n) { return $r + (($n % 3 == 0 || $n % 5 == 0) ? $n : 0); }
print array_reduce(range(0, 999), "multiple", 0) . "\n";

?>
