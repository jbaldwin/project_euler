<?php

/**
 * Consider quadratic Diophantine equations of the form:
 *
 *      x^2 - Dy^2 = 1
 *
 * For example, when D=13, the minimal solution in x is 649^2 - 13 * 180^2 = 1.
 *
 * It can be assumed that there are no solutions in positive integers when D is square.
 *
 * By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
 *
 *      3^2 - 2*2^2 = 1
 *      2^2 - 3*1^2 = 1
 *      9^2 - 5*4^2 = 1
 *      5^2 - 6*2^2 = 1
 *      8^2 - 7*3^2 = 1
 *
 * Hence, by considering minmal solutions in x for D <= 7, the largest x obtain when D = 5.
 *
 * Find the value of D <= 1000 in minimal solutions of x for which the largest value of x is obtained.
 **/

$result = 0;
$pmax = gmp_init(0);

for($D = 2; $D <= 1000; $D++) {
    $limit = gmp_sqrt($D);
    if(gmp_perfect_square($D)) continue;

    $m = gmp_init(0);
    $d = gmp_init(1);
    $a = $limit;

    $numm1 = gmp_init(1);;
    $num = $a;

    $denm1 = gmp_init(0);
    $den = gmp_init(1);

    while(gmp_cmp(
        gmp_sub(
            gmp_mul($num, $num),
            gmp_mul($D, gmp_mul($den, $den))
        ),
        gmp_init(1)
    )
    ) {
        $m = gmp_sub(gmp_mul($d, $a), $m);
        $d = gmp_div(gmp_sub($D, gmp_mul($m, $m)), $d);
        $a = gmp_div(gmp_add($limit, $m), $d);

        $numm2 = $numm1;
        $numm1 = $num;
        $denm2 = $denm1;
        $denm1 = $den;

        $num = gmp_add(gmp_mul($a, $numm1), $numm2);
        $den = gmp_add(gmp_mul($a, $denm1), $denm2);
    }

    if(gmp_cmp($num, $pmax) > 0) {
        $pmax = $num;
        $result = $D;
    }
}

print $result;

?>
