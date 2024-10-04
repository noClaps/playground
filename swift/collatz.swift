func collatzLength(_ n: Int) -> Int {
	var count = 1
	var n = n

	while n != 1 {
		count += 1

		if n % 2 == 0 {
			n /= 2
		} else {
			n = 3 * n + 1
		}
	}

	return count
}

let n = 11
print(collatzLength(n))
