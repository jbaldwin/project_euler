<?php

/**
 * The square root of 2 can be written as an infinite continued fraction.
 *
 * sqrt(2) = 1 + (1 / (2 + (1 / (2 + 1 / (2 + (1 / (2 + ...)))))))
 *
 * The infinite continued fraction can be written, sqrt(2) = [1;(2)],
 * (2) indicates that 2 repeats ad infinitum.  In a similar way,
 * sqrt(23) = [4;(1,3,1,8)].
 *
 * It turns out that the squence of partial values of continued fractions
 * for square roots provide the best rational approimations.  Let us
 * consider the convergents for sqrt(2).
 *
 * 1 + (1 / 2) = 3 / 2
 *
 * 1 + (1 / (2 + (1 / 2))) = 7 / 5
 *
 * 1 + (1 / (2 + (1 / (2 + (1 / 2))))) = 17 / 12
 *
 * 1 + (1 / (2 + 1( / (2 + (1 / (2 + 1 / 2)))))) = 41/ 29
 *
 * Hence the sequence of the first ten convergents of sqrt(2) are:
 *
 * 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3364/2378, ...
 *
 * What is most surprising is that the important mathematical constant,
 * e = [2;1,2,1, 1,4,1, 1,6,1, ..., 1 2k, 1, ...].
 *
 * The first ten terms in the sequence of convergents of e are:
 *
 * 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
 *
 * The sum of the digits in the numerator of the 10th convergent is 1+4+5+7=17.
 *
 * Find the sum of digits in the numerator of the 100th convergent of the
 * continued fraction for e.
**/

function digitSum($s) {
    $sum = 0;
    for($i = 0; $i < strlen($s); $i++) {
        $sum += (int)$s[$i];
    }
    return $sum;
}

// n_k = a_k * n_(k-1) + n_(k-2)

$n_k1 = gmp_init(1, 10);
$n = gmp_init(2, 10);

for($i = 2; $i <= 100; $i++) {
    $n_k2 = $n_k1;

    $a_k = ($i % 3 == 0) ? 2 * ($i / 3) : 1;
    $n_k1 = $n;
    $n = gmp_add(gmp_mul(strval($a_k), $n_k1), $n_k2);
}

print digitSum(gmp_strval($n));

?>
