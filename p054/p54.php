<?php

/**
Poker hands

In the card game poker, a hand consists of five cards and are ranked, from lowest to highest,
in the following way:

	* High Card: Highest value card.
	* One Pair: Two cards of the same value.
	* Two Pairs: Two different pairs.
	* Three of a Kind: Three cards of the same value.
	* Straight: All cards are consecutive values.
	* Flush: All cards of the same suit.
	* Full House: Three of a kind and a pair.
	* Four of a Kind: Four cards of the same value.
	* Straight Flush: All cards are consecutive values of same suit.
	* Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example,
a pair of eights beats a pair of fives (see example 1 below).  But if two ranks tie, for example, both
players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if
the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand	Player 1		Player 2		Winner
1	5H 5C 6S 7S KD		2C 3S 8S 8D TD		Player 2
	Pair of Fives		Pair of Eights

2	5D 8C 9S JS AC		2C 5C 7D 8S QH		Player 1
	Highest card Ace	Highest Card Queend

3	2D 9C AS AH AC		3D 6D 7D TD QD		Player 2
	Three Aces          Flush with Diamonds

4	4D 6S 9H QH QC		3D 6D 7H QD QS		Player 1
	Pair of Queens		Pair of Queens
	Highest card Nine	Highest Card Seven

5	2H 2D 4C 4D 4S		3C 3D 3S 9S 9D		Player 1
	Full House          Full House
	With Three Fours	With Three Threes

The file, poker.txt, contains one-thousand random hands dealt to two players.  Each line of the file
contains ten cards (separated by a single space); the first five are Player 1's cards and the last five
are Player 2's cards.  You can assume that all hands are valid (no invalid characters or repeated cards),
each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?
**/

$g_values = array(
	'2' => 2,
	'3' => 3,
	'4' => 4,
	'5' => 5,
	'6' => 6,
	'7' => 7,
	'8' => 8,
	'9' => 9,
	'T' => 10,
	'J' => 11,
	'Q' => 12,
	'K' => 13,
	'A' => 14
);


function high_card($hand) {
	global $g_values;

	$high = 0;
	foreach($hand as $card) {
		$high = max($high, $g_values[$card[0]]);
	}
	return $high;
}

function one_pair($hand) {
	global $g_values;

	$pair = 0;
	$numbers = array();

	for($i =      0; $i < count($hand); $i++) {
	for($j = $i + 1; $j < count($hand); $j++) {
		if($i == $j) continue;
		if($hand[$i][0] == $hand[$j][0]) {
			$pair = $g_values[$hand[$i][0]];
            $numbers[] = $pair;

			$remaining = array();
			for($k = 0; $k < count($hand); $k++) {
				if($g_values[$hand[$k][0]] != $pair) {
                    $remaining[] = $g_values[$hand[$k][0]];
                }
            }

			rsort($remaining, SORT_NUMERIC);
			foreach($remaining as $r) {
                $numbers[] = $r;
			}
			return $numbers;
		}
	}
	}

	return false;
}

function two_pair($hand) {
	global $g_values;

	$first = 0;
	$second = 0;

	for($i =      0; $i < count($hand); $i++) {
	for($j = $i + 1; $j < count($hand); $j++) {
		if($i == $j) continue;
		if($hand[$i][0] == $hand[$j][0]) {
			if($first == 0) {
				$first =  $g_values[$hand[$i][0]];
			} else {
				$second = $g_values[$hand[$i][0]];
				$pairs = array($first, $second);
				rsort($pairs, SORT_NUMERIC);
				return $pairs;
			}
		}
	}
	}

	return false;
}

function three_of_a_kind($hand) {
	global $g_values;

	for($i = 0; $i < count($hand); $i++) {
		$count = 1;
		for($j = 0; $j < count($hand); $j++) {
			if($i == $j) continue;
			if($hand[$i][0] == $hand[$j][0]) {
				$count++;
			}
		}
		if($count == 3) {
			return $g_values[$hand[$i][0]];
		}
	}
	return false;
}

function straight($hand) {
	global $g_values;

	$cards = array();
	for($i = 0; $i < count($hand); $i++) {
		$cards[] = $g_values[$hand[$i][0]];
	}
	rsort($cards, SORT_NUMERIC);

	for($i = 1; $i < count($cards); $i++) {
		if($cards[$i - 1] - 1 != $cards[$i]) {
			return false;
		}
	}

	return $cards;
}

function pflush($hand) {
	global $g_values;

	for($i = 1; $i < count($hand); $i++) {
		if($hand[0][1] != $hand[$i][1]) {
			return false;
		}
	}

	$cards = array();
	for($i = 0; $i < count($hand); $i++) array_push($cards, $g_values[$hand[$i][0]]);
	rsort($cards, SORT_NUMERIC);
	return $cards;
}

function full_house($hand) {
	global $g_values;

	$numbers = array();
	for($i = 0; $i < count($hand); $i++) {
		$numbers[] = $g_values[$hand[$i][0]];
	}
	rsort($numbers, SORT_NUMERIC);

	if($numbers[0] == $numbers[1] && $numbers[0] == $numbers[2] &&
	   $numbers[0] != $numbers[3] &&
	   $numbers[3] == $numbers[4]) {
		return array($numbers[0], $numbers[3]);
	}

	if($numbers[0] == $numbers[1] &&
	   $numbers[0] != $numbers[2] &&
	   $numbers[2] == $numbers[3] && $numbers[2] == $numbers[4]) {
		return array($numbers[2], $numbers[0]);
	}

	return false;
}

function four_of_a_kind($hand) {
	global $g_values;

	for($i = 0; $i < 2; $i++) {
		$count = 0;
		for($j = $i + 1; $j < count($hand); $j++) {
			if($hand[$i][0] == $hand[$j][0]) $count++;
		}
		if($count == 4) {
			$high_card = 0;
			for($k = 0; $k < count($hand); $k++) {
				if($k == $i) continue;
				if($hand[$i][0] != $hand[$k][0]) {
					$high_card = $g_values[$hand[$k][0]];
				}
			}

			return array($g_values[$hand[$i][0]], $high_card);
		}
	}

	return false;
}

function straight_flush($hand) {
	global $g_values;

	$numbers = array();

	for($i = 0; $i < count($hand); $i++) {
		$numbers[] = $g_values[$hand[$i][0]];
		if($hand[0][1] != $hand[$i][1]) return false;
	}
	rsort($numbers, SORT_NUMERIC);

	for($i = 1; $i < count($numbers); $i++) {
		if($numbers[$i - 1] - 1 != $numbers[$i]) return false;
	}

	return $numbers;
}

function winner($h1, $h2) {

	$funcs = array(
		"straight_flush",
		"four_of_a_kind",
		"full_house",
		"pflush",
		"straight",
		"three_of_a_kind",
		"two_pair",
		"one_pair",
		"high_card"
	);


	foreach($funcs as $func) {
		$p1 = $func($h1);
		$p2 = $func($h2);

		if($p1 == false && $p2 == false) continue;
		if($p2 == false) return true;

		// array of values
		if(is_array($p1)) {
			for($i = 0; $i < count($p1); $i++) {
				if($p1[$i] == $p2[$i]) continue;
				return $p1[$i] > $p2[$i];
			}
			print "error!\n";
			continue;	// all entries matched??
		}

		// integers only
		if($p1 == $p2) continue;
		return ($p1 > $p2);
	}
}

$contents = file_get_contents("poker.txt");
if($contents == false) { print "unable to read poker.txt\n"; die(); }

$hands = explode("\n", $contents);

$count = 0;
foreach($hands as $hand) {
	if(empty($hand)) continue;

	$h2 = explode(" ", $hand);
	$h1 = array_splice($h2, 0, 5);

	if(winner($h1, $h2)) {
		$count++;
	}
}

print $count;

?>
