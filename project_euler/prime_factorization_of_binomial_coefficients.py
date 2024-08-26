def solve(n, m):
	least_prime_factor = list(range(n + 1))

	for i in range(2, int(n ** 0.5) + 1):
		if least_prime_factor[i] != i:
			continue
		for j in range(i * i, n + 1, i):
			if least_prime_factor[j] == j:
				least_prime_factor[j] = i

	sum_of_prime_factors = [0] * (n + 1)
	for i in range(2, n + 1):
		sum_of_prime_factors[i] = sum_of_prime_factors[i // least_prime_factor[i]] + least_prime_factor[i]

	m = min(m, n - m)
	ans = 0
	for i in range(m):
		ans += sum_of_prime_factors[n - i] - sum_of_prime_factors[i + 1]
	return ans

print(solve(10, 3))
print(solve(20_000_000, 15_000_000))