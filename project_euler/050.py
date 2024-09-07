def consecutive_prime_sum(n):
	is_prime = [True] * (n)
	is_prime[0] = is_prime[1] = False

	for i in range(2, n):
		if i * i >= n:
			break

		if not is_prime[i]:
			continue

		for j in range(i * i, n, i):
			is_prime[j] = False

	primes = [i for i in range(2, n) if is_prime[i]]

	ans = (0, 0)
	for i in range(len(primes)):
		sum = 0
		length = 0
		for j in range(i, len(primes)):
			sum += primes[j]
			length += 1
			if sum >= n:
				break
			if is_prime[sum]:
				ans = max(ans, (length, sum))
	
	return ans

print(consecutive_prime_sum(100))
print(consecutive_prime_sum(1000))
print(consecutive_prime_sum(1000000))