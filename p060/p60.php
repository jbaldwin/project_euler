<?php

require_once "../lib/prime.php";

$primes = array();
$stop = 10000;

function is_prime_cache($p) {
    global $primes;

    if(!isset($primes[$p])) {
        $primes[$p] = is_prime($p);
    }
    return $primes[$p];
}

for($a = 2; $a < $stop; $a++) {
    if(!is_prime_cache($a)) continue;

for($b = $a + 1; $b < $stop; $b++) {
    if(!is_prime_cache($b)) continue;

    $ab = $a . $b;
    $ba = $b . $a;

    if(!is_prime_cache($ab)) continue;
    if(!is_prime_cache($ba)) continue;

for($c = $b + 1; $c < $stop; $c++) {
    if(!is_prime_cache($c)) continue;

    $ac = $a . $c;
    $bc = $b . $c;
    $ca = $c . $a;
    $cb = $c . $b;

    if(!is_prime_cache($ac)) continue;
    if(!is_prime_cache($bc)) continue;
    if(!is_prime_cache($ca)) continue;
    if(!is_prime_cache($cb)) continue;

for($d = $c + 1; $d < $stop; $d++) {
    if(!is_prime_cache($d)) continue;

    $ad = $a . $d;
    $bd = $b . $d;
    $cd = $c . $d;
    $da = $d . $a;
    $db = $d . $b;
    $dc = $d . $c;


    if(!is_prime_cache($ad)) continue;
    if(!is_prime_cache($bd)) continue;
    if(!is_prime_cache($cd)) continue;
    if(!is_prime_cache($da)) continue;
    if(!is_prime_cache($db)) continue;
    if(!is_prime_cache($dc)) continue;


for($e = $d + 1; $e < $stop; $e++) {
    if(!is_prime_cache($e)) continue;

    $ae = $a . $e;
    $be = $b . $e;
    $ce = $c . $e;
    $de = $d . $e;
    $ea = $e . $a;
    $eb = $e . $b;
    $ec = $e . $c;
    $ed = $e . $d;


    if(!is_prime_cache($ae)) continue;
    if(!is_prime_cache($be)) continue;
    if(!is_prime_cache($ce)) continue;
    if(!is_prime_cache($de)) continue;
    if(!is_prime_cache($ea)) continue;
    if(!is_prime_cache($eb)) continue;
    if(!is_prime_cache($ec)) continue;
    if(!is_prime_cache($ed)) continue;

    print $a . " " . $b . " " . $c . " " . $d . " " . $e . " sum=" . ($a + $b + $c + $d + $e) . "\n";
    die();
}
}
}
}
}


?>

