<?php

function fraction_reduce(&$numerator, &$denominator) {
	for($i = $numerator; $i >= 1; $i--) {
		if($numerator % $i == 0 && $denominator % $i == 0) {
			$numerator /= $i;
			$denominator /= $i;
			break;
		}
	}
}

?>
