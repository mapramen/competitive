def is_square(n):
	return n == int(n ** 0.5) ** 2

def solve(n):
	least_prime_factor = list(range(n))
	for p in range(2, int(n ** 0.5) + 1):
		if least_prime_factor[p] != p:
			continue
		for i in range(p * p, n, p):
			if least_prime_factor[i] == i:
				least_prime_factor[i] = p

	least_prime_factor_contribution = [1] * n
	non_least_prime_factor_contribution = [1] * n
	
	for i in range(2, n):
		p = least_prime_factor[i]
		j = i // p
		if least_prime_factor[j] != p:
			non_least_prime_factor_contribution[i] = least_prime_factor_contribution[j] * non_least_prime_factor_contribution[j]
			least_prime_factor_contribution[i] = 1 + p * p
		else:
			non_least_prime_factor_contribution[i] = non_least_prime_factor_contribution[j]
			least_prime_factor_contribution[i] = 1 + p * p * least_prime_factor_contribution[j]

	return sum(i for i in range(1, n) if is_square(least_prime_factor_contribution[i] * non_least_prime_factor_contribution[i]))

print(solve(64 * 10 ** 6))