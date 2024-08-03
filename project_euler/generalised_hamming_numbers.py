from queue import Queue

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

def get_primes(n):
	return list(filter(is_prime, range(2, n + 1)))

def generalised_hamming_numbers(n, m):
	primes = get_primes(n)

	Q = Queue()
	Q.put((0, 1))

	ans = 0
	while not Q.empty():
		(i, x) = Q.get()
		ans += 1

		for p in primes:
			if p < i:
				continue

			if x * p <= m:
				Q.put((p, x * p))
	
	return ans

print(generalised_hamming_numbers(5, 10**8))
print(generalised_hamming_numbers(100, 10**9))