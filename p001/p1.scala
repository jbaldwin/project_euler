object p1 {
	def main(args: Array[String]) {
		print(
			(0 until 1000).foldLeft(0)
				((b, a) =>
					if(a % 3 == 0 || a % 5 == 0) a + b else b
				)
		)
	}
}