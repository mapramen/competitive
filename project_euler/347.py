def largest_divisible_number(n, a, b):
	if n < a * b:
		return 0
	
	n //= (a * b)

	if n == 1:
		return a * b
	
	x, y, ans = 1, 1, 1
	while x <= n and y >= 1:
		while x * y <= n:
			y *= b
		
		while x * y > n:
			y //= b

		ans = max(ans, a * b * x * y)
		x *= a

	return ans

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