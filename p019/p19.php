<?php

/**
You are given the following information, but you may prefer to do some research yourself.

* 1 Jan 1900 was a Monday.
* Thirty days has September,
  April, June and November,
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years twenty-nine.
* A leap year occurs on any year evenly divisible by 4, but not on a century unless it is
  divisible by 400.

How many Sundays fell on the first of the month during the twentieth centruy (1 Jan 1901 to 31 Dec 2000)?
**/

class Days {
	const Sunday = 0;
	const Monday = 1;
	const Tuesday = 2;
	const Wednesday = 3;
	const Thursday = 4;
	const Friday = 5;
	const Saturday = 6;
}

class Months {
	const January = 30;//31;
	const February = 58;//28;
	const March = 89;//31;
	const April = 119;//30;
	const May = 150;//31;
	const June = 180;//30;
	const July = 211;//31;
	const August = 242;//31;
	const September = 272;//30;
	const October = 303;//31;
	const November = 333;//30;
	const December = 364;//31;
}

// first day of each month
$months = array(
	0,//30,
	31,//58,
	59,//89
	90,//119
	120,//150,
	151,//180,
	181,//211,
	212,//242,
	243,//272,
	273,//303,
	304,//333,
	334//364
);

function leap_year($year) {
	// a century is a leap year if evenly divisible by 4 and 400
	if($year % 100 == 0) {
		return ($year % 4 == 0 && $year % 400 == 0) ? 1 : 0;
	}
	// otherwise just every 4 years
	return ($year % 4 == 0) ? 1 : 0;
}

$start_day = Days::Tuesday;
$total_sundays = 0;
$start_year = 1901;
$end_year = 2000;

for($year = $start_year; $year <= $end_year; $year++) {
	// setup leap year for this year
	$leap_year = leap_year($year);

	// find the first sunday
	$day = $start_day;
	while($day % 7 != 0) {
		$day++;
	}
	// for each sunday in the year check if it falls on the first of the month
	while($day < 365 + $start_day + $leap_year) {
		for($j = 0; $j < count($months); $j++) {
			// jan/feb are not affected by leap years
			$first = $months[$j] + $start_day + (($j >= 2) ? $leap_year : 0);
			if($day == $first) $total_sundays++;
		}
		$day += 7;
	}

	// calculate the next years starting day
	// it is always +1 day and +2 on a leapyear,
	// so a tuesday in 1901 will result in a wednesday on 1902
	// and a tuesday in 1904 will result in a thursday on 1905
	$start_day = ($start_day + 1 + $leap_year) % 7;
}

print $total_sundays;
?>
