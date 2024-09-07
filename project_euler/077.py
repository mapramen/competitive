def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

def prime_summations(m):
	dp = [[1]]

	primes = [0]
	i = 1
	while True:
		if is_prime(i):
			primes.append(i)
		
		dp.append([0] * len(primes))

		for x, p in enumerate(primes):
			if p == 0:
				continue

			dp[i][x] = dp[i][x - 1]

			j = i - p
			dp[i][x] += dp[j][x] if j >= p else dp[j][-1]

		if dp[i][-1] > m:
			break

		i += 1

	return i

print(prime_summations(5000))