<?php

/**
Cyclical figurate numbers

Triangle, square, pentagonal, hexagonal, heptagonal, and octagonal numbers are
all figurate (polygonal) numbers and are generated by the following formulae:

Triangle        P3,n=n(n+1)/2       1, 3, 6, 10, 15, ...
Square          P4,n=n2             1, 4, 9, 16, 25, ...
Pentagonal      P5,n=n(3n-1)/2      1, 5, 12, 22, 35, ...
Hexagonal       P6,n=n(2n-1)        1, 6, 15, 28, 45, ...
Heptagonal      P7,n=n(5n-3)/2      1, 7, 18, 34, 55, ...
Octagonal       P8,n=n(3n-2)        1, 8, 21, 40, 65, ...

The ordered set of three 4-digit numbers: 8128, 2882, 8281,
has three interesting properties.

    * The set is cyclic, in that the last two digits of each number is the first two digits of the next number (including the last number with the first).
    * Each polygonal type: triangle (P3,127=8128), square (P4,91=8281), and pentagonal (P5,44=2882), is represented by a different number in the set.
    * This is the only set of 4-digit numbers with this property.

Find the sum of the only ordered set of six cyclic 4-digit numbers for which
each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and
octagonal, is represented by a different number in the set.
**/

function triangle($n) { return $n * ($n + 1) / 2; }
function square($n) { return $n * $n; }
function pentagonal($n) { return $n * (3 * $n - 1) / 2; }
function hexagonal($n) { return $n * (2 * $n - 1); }
function heptagonal($n) { return $n * (5 * $n - 3) / 2; }
function octagonal($n) { return $n * (3 * $n - 2); }

$types = array(
    "triangle" => array(),
    "square" => array(),
    "pentagonal" => array(),
    "hexagonal" => array(),
    "heptagonal" => array(),
    "octagonal" => array()
);

class Value {
    public $n;
    public $v;

    function __construct($n, $v) {
        $this->n = $n;
        $this->v = $v;
    }
}

foreach($types as $type => $values) {
    $n = 1;
    do {
        $v = $type($n);
        if($v >= 1000 && $v < 10000) {
            $types[$type][] = new Value($n, $v);
        }
        $n++;
    } while($v < 10000);
}

function cyclic($types, $remaining, $aChain) {
    if(count($aChain) == 6) {

        $first = strval($aChain[0]->v);
        $last = strval($aChain[5]->v);
        if($first[0] != $last[2] || $first[1] != $last[3]) return;

        $sum = 0;
        $duplicate = false;
        for($i = 0; $i < count($aChain); $i++) {
            for($j = 0; $j < count($aChain); $j++) {
                if($i == $j) continue;

                if($aChain[$i]->n == $aChain[$j]->n) {
                    $duplicate = true;
                }
            }
        }

        if($duplicate) return;

        foreach($aChain as $value) {
            $sum += $value->v;
            //print $value->v . ", ";
        }
        //print "\n";
        //foreach($aChain as $value) {
        //    print $value->n . ", ";
        //}
        print $sum;
    }

    $current = strval($aChain[count($aChain) - 1]->v);
    $c0 = $current[2];
    $c1 = $current[3];

    foreach($remaining as $rkey => $rvalue) {
        if(!is_array($types[$rvalue])) {
            print gettype($types[$rvalue]). "\n";
            continue;
        }
        foreach($types[$rvalue] as $vkey => $vvalue) {
            $svalue = strval($vvalue->v);
            $sv2 = $svalue[0];
            $sv3 = $svalue[1];

            if($c0 == $sv2 && $c1 == $sv3) {
                $nextChain = array_merge($aChain, array($vvalue));
                $r = array_merge(array(), $remaining);
                unset($r[array_search($rvalue, $r)]);
                cyclic($types, $r, $nextChain);
            }
        }
    }
}

foreach($types["triangle"] as $triangle) {
    $remaining = array_merge(array(), array_keys($types));
    unset($remaining[0]);
    cyclic($types, $remaining, array($triangle));
}

?>
