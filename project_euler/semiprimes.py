from math import sqrt

n = 100000000

smallest_prime_factor = list(range(n + 1))

for i in range(2, int(sqrt(n)) + 1):
	if smallest_prime_factor[i] != i:
		continue
	for j in range(i * i, n + 1, i):
		if smallest_prime_factor[j] == j:
			smallest_prime_factor[j] = i

prime_divisors = [0] * (n + 1)
for i in range(2, n + 1):
	prime_divisors[i] = 1 + prime_divisors[i // smallest_prime_factor[i]]

ans = sum(1 for i in range(2, n + 1) if prime_divisors[i] == 2)
print(ans)