def calculate(p):
	i, factorial, ans = 2, p - 1, p - 1
	while i <= 5:
		factorial = (factorial * pow(p - i + 1, p - 2, p)) % p
		ans = (ans + factorial) % p
		i += 1
	return ans

def solve(n):
	is_prime = [True] * (n + 1)

	is_prime[0] = is_prime[1] = False
	for p in range(2, int(n ** 0.5) + 1):
		if not is_prime[p]:
			continue
		for i in range(p * p, n + 1, p):
			is_prime[i] = False

	return sum(calculate(p) for p in range(5, n) if is_prime[p])

for length in range(1, 9):
	n = 10 ** length
	print(f"10**{length}: {solve(n)}")