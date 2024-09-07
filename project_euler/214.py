def solve(limit):
	least_prime_factor = list(range(limit))
	for i in range(2, int(limit ** 0.5) + 1):
		if least_prime_factor[i] != i:
			continue
		for j in range(i * i, limit, i):
			if least_prime_factor[j] == j:
				least_prime_factor[j] = i

	phi = [1] * limit
	for i in range(2, limit):
		p = least_prime_factor[i]
		phi[i] = phi[i // p] * (p if least_prime_factor[i // p] == p else p - 1)

	chain_length = [0] * limit
	chain_length[1] = 1
	for i in range(2, limit):
		chain_length[i] = chain_length[phi[i]] + 1

	return sum(i for i in range(2, limit) if chain_length[i] == 25 and least_prime_factor[i] == i)

print(solve(4 * 10 ** 7))