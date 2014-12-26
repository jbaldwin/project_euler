object p2 {
	def main(args: Array[String]) {
		var total : Long = 0
		var last  : Long = 1
		var curr  : Long = 2
		var next  : Long = 0

		while(next <= 4000000) {
			if(curr % 2 == 0) {
				total += curr
			}
			next = last + curr
			last = curr
			curr = next
		}

		print(total)
	}
}