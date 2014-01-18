<?php

/**
Cubic permutations

The cube, 41063625 (345^3), can be permuted to produce two other cudes: 56623104 (384^3)
and 66430125 (405^3).  In fact, 41063625 is the smallest cube which has exactly three
permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
**/

function create_permutation_table($n) {
    $s = strval($n);
    
    $table = array(
        '0' => 0, 
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0
    );

    for($i = 0; $i < strlen($s); $i++) {
        $table[$s[$i]]++;
    }

    return $table;
}

$cube_tables = array();
for($i = 100; $i < 10000; $i++) {
    $cube = $i * $i * $i;
    $cube_tables[$i] = array($cube, create_permutation_table($cube));
}

$cube_matches = array();
for($i = 100; $i < 1000; $i++) {
    $matches = 1;
    for($j = 100; $j < 1000; $j++) {
        if($i == $j) continue;

        if($cube_tables[$j] == $cube_tables[$i]) $matches++;
    }
    $cube_matches[$i] = $matches;
}

for($i = 100; $i < 1000; $i++) {
    if($cube_matches[$i] == 5) print $i . " (5)\t" . ($i * $i * $i) . "\n";
    if($cube_matches[$i] == 3) print $i . " (3)\t" . ($i * $i * $i) . "\n";
}

?>

