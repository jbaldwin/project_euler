<?php

/**
Sub-string divisibility

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9
in some order, but it also has a rather interesting sub-string divisibility property.

Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on.  In this way, we not the following:

	* d_2 d_3 d_4 = 406 is divisible by 2
	* d_3 d_4 d_5 = 063 is divisible by 3
	* d_4 d_5 d_6 = 635 is divisible by 5
	* d_5 d_6 d_7 = 357 is divisible by 7
	* d_6 d_7 d_8 = 572 is divisible by 11
	* d_7 d_8 d_9 = 728 is divisible by 13
	* d_8 d_9 d_10= 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
**/

function permute($prefix, $str, &$pSum) {
	$len = strlen($str);
	if($len == 0) {
		if($prefix[0] != '0') {
            static $divs = array(2,3,5,7,11,13,17);
            $is_divisible = true;
	        for($i = 1; $i <= 7; $i++) {
		        $d = $prefix[$i] . $prefix[$i + 1] . $prefix[$i + 2];
		        if($d % $divs[$i - 1] != 0) {
                    $is_divisible = false;
                    break;
		        }
	        }

            if($is_divisible) {
                $pSum += $prefix;
            }
		}
	} else {
		for($i = 0; $i < $len; $i++) {
			permute($prefix . $str[$i], substr($str, 0, $i) . substr($str, $i + 1, $len), $pSum);
		}
	}
}

$sum = 0;
$start = "0123456789";
permute("", $start, $sum);

print $sum;

?>
