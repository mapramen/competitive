def totient_permutation(n):
	def is_prime(n):
		return n > 1 and all(n % i != 0 for i in range(2, int(n**0.5)+1))
	
	def are_permutation(a, b):
		return sorted(str(a)) == sorted(str(b))
	
	primes = [i for i in range(2, int(2 * n ** 0.5) + 1) if is_prime(i)]
	
	ans = (n + 1, n + 1)
	for i in range(len(primes) - 1, -1, -1):
		for j in range(i - 1, -1, -1):
			x = primes[i] * primes[j]
			if x > n:
				continue
			phi = (primes[i] - 1) * (primes[j] - 1)
			if are_permutation(x, phi):
				ans = min(ans, (x / phi, x, primes[i], primes[j]))
	
	return ans

print(totient_permutation(10000000))