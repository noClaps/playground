func fib(_ n: Int) -> Int {
	if n < 2 {
		return n
	}

	return fib(n - 1) + fib(n - 2)
}

let n = 20
print(fib(n))
