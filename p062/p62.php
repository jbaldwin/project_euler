<?php

/**
Cubic permutations

The cube, 41063625 (345^3), can be permuted to produce two other cudes: 56623104 (384^3)
and 66430125 (405^3).  In fact, 41063625 is the smallest cube which has exactly three
permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
**/

ini_set('memory_limit', '256M');

$stdin = fopen("php://stdin", "r");
$start = 100;
$stop = 10000;

function create_permutation_table($s) {
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
for($i = $start; $i < $stop; $i++) {
	$s = strval($i);
	$cube = bcpow($s, "3");
    $cube_tables[$i] = array($cube, create_permutation_table($cube));
}

$cube_matches = array();
for($i = $start; $i < $stop; $i++) {
    $matches = 1;
    for($j = $start; $j < $stop; $j++) {
        if($i == $j) continue;

        if($cube_tables[$j][1] == $cube_tables[$i][1]) $matches++;
    }
	if($matches >= 5) {
		$cube_matches[$i] = $matches;
		break;
	}
}

foreach($cube_matches as $i => $m) {
    print $i . " (" . $m . ")\t\t" . ($i * $i * $i) . "\n";
	//if($m == 4) print $i . " (4)\t" . ($i * $i * $i) . "\n";
    //if($m == 3) print $i . " (3)\t" . ($i * $i * $i) . "\n";
}

?>

