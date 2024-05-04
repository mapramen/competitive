def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

def prime_power_triples(n):
	S = set()
	square_root_primes = [i ** 2 for i in range(2, int(n ** 0.5) + 1) if is_prime(i)]
	cube_root_primes = [i ** 3 for i in range(2, int(n ** (1 / 3)) + 1) if is_prime(i)]
	fourth_root_primes = [i ** 4 for i in range(2, int(n ** 0.25) + 1) if is_prime(i)]

	for i in square_root_primes:
		for j in cube_root_primes:
			for k in fourth_root_primes:
				if i + j + k <= n:
					S.add(i + j + k)

	return len(S)

print(prime_power_triples(50000000))