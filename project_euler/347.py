def largest_prime_divisible_number(n, primes):
	if n == 1:
		return 1
	
	primes = sorted(primes)
	nums = [1]
	candidates = [1 for _ in primes]
	candidate_indexes = [0 for _ in primes]

	while True:
		min_candidate = min(candidates)
		if min_candidate > n:
			break

		nums.append(min_candidate)

		for i, prime in enumerate(primes):
			if min_candidate == candidates[i]:
				candidate_indexes[i] += 1
				candidates[i] = prime * nums[candidate_indexes[i]]

	return nums[-1]

def largest_divisible_number(n, a, b):
	return 0 if n < a * b else a * b * largest_prime_divisible_number(n // (a * b), [a, b])

def solve(n):
	is_prime = [True] * (n + 1)

	is_prime[0] = is_prime[1] = False
	for i in range(2, int(n ** 0.5) + 1):
		if not is_prime[i]:
			continue
		for j in range(i * i, n + 1, i):
			is_prime[j] = False

	primes = []
	ans = 0

	for i in range(2, n + 1):
		if not is_prime[i]:
			continue
		for prime in primes:
			if prime * i > n:
				break
			ans += largest_divisible_number(n, i, prime)
		primes.append(i)

	return ans

for length in range(1, 8):
	n = 10 ** length
	print(f"10**{length}: {solve(n)}")