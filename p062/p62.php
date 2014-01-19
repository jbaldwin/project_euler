<?php

/**
Cubic permutations

The cube, 41063625 (345^3), can be permuted to produce two other cudes: 56623104 (384^3)
and 66430125 (405^3).  In fact, 41063625 is the smallest cube which has exactly three
permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
**/

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
    $cube_tables[$i] = create_permutation_table($cube);
}


$cube_counts = array();
for($i = $start; $i < $stop; $i++) {
	$key = "";
	for($j = 0; $j < count($cube_tables[$i]); $j++)
		$key .= $cube_tables[$i][$j];
	if(!isset($cube_counts[$key]))
		$cube_counts[$key] = array($i, 1);
	else
		$cube_counts[$key][1]++;
}

foreach($cube_counts as $c) {
	if($c[1] >= 5) {
		print $c[0] . " cubed = " . ($c[0] * $c[0] * $c[0]) . "\n";
		break;
	}
}

?>

