def is_prime(n):
	if n < 2:
		return False

	if n == 2 or n == 3:
		return True

	if n % 2 == 0:
		return False

	r, d = 0, n - 1
	while d % 2 == 0:
		r += 1
		d = d // 2

	bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	
	for a in bases:
		if a >= n:
			break

		x = pow(a, d, n)
		
		for _ in range(r - 1):
			x = (x * x) % n
		
		if x == 1 or x == n - 1:
			continue
		
		return False

	return True

def solve(limit):
	small_primes = [p for p in range(2, int(limit ** 0.5) + 1) if is_prime(p)]
	valid = [True] * (limit + 1)

	for p in small_primes:
		for r in range(p):
			if (2 * r * r + p - 1) % p != 0:
				continue
			for i in range(r + p, limit + 1, p):
				valid[i] = False

	return sum(1 for i in range(2, limit + 1) if valid[i] and is_prime(2 * i * i - 1))

print(solve(50 * 10 ** 7))