<?php

/**
Prime pair sets

The primes, 3, 7, 109, and 673, are quite remarkable.  By taking any two primes and 
concatenating them in any order the result will always be prime.  For example, taking
7 and 109 both 7109 and 1097 are prime.  The sum of these four primes, 792, represents
the lowest sum for a set of four primes with this property.

Fnd the lowest sum for a set of five primes for which any two primes concatenate to 
produce another prime.
**/

require_once "../lib/prime.php";

$sieve = prime_sieve(1000000);
$sievebound = count($sieve);
$stop = 100000;

//prime_sieve_value()
//prime_sieve_index()

for($a = 0; $a <= $stop; $a++) {
    if(!$sieve[$a]) continue;
    $aprime = prime_sieve_value($a);
for($b = $a + 1; $b <= $stop; $b++) {
    if(!$sieve[$b]) continue;
    $bprime = prime_sieve_value($b);

    $ab = $aprime . $bprime;
    if(!$sieve[prime_sieve_index($ab)]) continue;
    $ba = $bprime . $aprime;
    if(!$sieve[prime_sieve_index($ba)]) continue;
for($c = $b + 1; $c <= $stop; $c++) {
    if(!$sieve[$c]) continue;
    $cprime = prime_sieve_value($c);

    $ac = $aprime . $cprime;
    if(!$sieve[prime_sieve_index($ac)]) continue;
    $bc = $bprime . $cprime;
    if(!$sieve[prime_sieve_index($bc)]) continue;
    $ca = $cprime . $aprime;
    if(!$sieve[prime_sieve_index($ca)]) continue;
    $cb = $cprime . $bprime;
    if(!$sieve[prime_sieve_index($cb)]) continue;

for($d = $c + 1; $d <= $stop; $d++) {
    if(!$sieve[$d]) continue;
    $dprime = prime_sieve_value($d);

    $ad = $aprime . $dprime;
    if(!$sieve[prime_sieve_index($ad)]) continue;
    $bd = $bprime . $dprime;
    if(!$sieve[prime_sieve_index($bd)]) continue;
    $cd = $cprime . $dprime;
    if(!$sieve[prime_sieve_index($cd)]) continue;
    $da = $dprime . $aprime;
    if(!$sieve[prime_sieve_index($da)]) continue;
    $db = $dprime . $bprime;
    if(!$sieve[prime_sieve_index($db)]) continue;
    $dc = $dprime . $cprime;
    if(!$sieve[prime_sieve_index($dc)]) continue;

for($e = $d + 1; $e <= $stop; $e++) {
    //$aprime = prime_sieve_value($a);
    //$bprime = prime_sieve_value($b);
    //$cprime = prime_sieve_value($c);
    //$dprime = prime_sieve_value($d);
    $eprime = prime_sieve_value($e);

    print $aprime . " " . $bprime . " " . $cprime . " " . $dprime . " " . $eprime . "\n";

    // example given
    // 3 . 7 == 37
    // 3 . 109 = 3109
    // 3 . 673 = 3673
    // 7. 3 = 73
    // 7 . 109 = 7109
    // 7 . 673 = 7673
    // 109 . 3 = 1093
    // 109 . 7 = 1097
    // 109 . 673 = 109673
    // 673 . 3 = 6733
    // 673 . 7 = 6737
    // 673 . 109 = 673109

    /*$ab = $aprime . $bprime;
    if(!$sieve[prime_sieve_index($ab)]) continue;
    $ac = $aprime . $cprime;
    if(!$sieve[prime_sieve_index($ac)]) continue;
    $ad = $aprime . $dprime;
    if(!$sieve[prime_sieve_index($ad)]) continue;*/
    $ae = $aprime . $eprime;
    if(!$sieve[prime_sieve_index($ae)]) continue;

    /*$ba = $bprime . $aprime;
    if(!$sieve[prime_sieve_index($ba)]) continue;
    $bc = $bprime . $cprime;
    if(!$sieve[prime_sieve_index($bc)]) continue;
    $bd = $bprime . $dprime;
    if(!$sieve[prime_sieve_index($bd)]) continue;*/
    $be = $bprime . $eprime;
    if(!$sieve[prime_sieve_index($be)]) continue;

    /*$ca = $cprime . $aprime;
    if(!$sieve[prime_sieve_index($ca)]) continue;
    $cb = $cprime . $bprime;
    if(!$sieve[prime_sieve_index($cb)]) continue;
    $cd = $cprime . $dprime;
    if(!$sieve[prime_sieve_index($cd)]) continue;/*
    $ce = $cprime . $eprime;
    if(!$sieve[prime_sieve_index($ce)]) continue;

    /*$da = $dprime . $aprime;
    if(!$sieve[prime_sieve_index($da)]) continue;
    $db = $dprime . $bprime;
    if(!$sieve[prime_sieve_index($db)]) continue;
    $dc = $dprime . $cprime;
    if(!$sieve[prime_sieve_index($dc)]) continue;*/
    $de = $dprime . $eprime;
    if(!$sieve[prime_sieve_index($de)]) continue;

    $ea = $eprime . $aprime;
    if(!$sieve[prime_sieve_index($ea)]) continue;
    $eb = $eprime . $bprime;
    if(!$sieve[prime_sieve_index($eb)]) continue;
    $ec = $eprime . $cprime;
    if(!$sieve[prime_sieve_index($ec)]) continue;
    $ed = $eprime . $dprime;
    if(!$sieve[prime_sieve_index($ed)]) continue;

    print ($aprime + $bprime + $cprime + $dprime + $eprime) . "\n";
    die();
}
}
}
}
}


?>

