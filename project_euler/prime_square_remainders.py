def solve(limit):
	primes = []

	n, p = 0, 2
	while True:
		if any(p % prime == 0 for prime in primes):
			p += 1
			continue
		
		n += 1
		primes.append(p)

		prime_square_remainder = 2 * n * p if n % 2 == 1 else 2
		print(n, p, prime_square_remainder)
		
		if prime_square_remainder > limit:
			break

		p += 1

solve(1e10)
