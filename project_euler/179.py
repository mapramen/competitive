from math import sqrt

n = 10000000

smallest_prime_factor = list(range(n + 1))

for i in range(2, int(sqrt(n)) + 1):
	if smallest_prime_factor[i] != i:
		continue
	for j in range(i * i, n + 1, i):
		if smallest_prime_factor[j] == j:
			smallest_prime_factor[j] = i

num_divisors = [1] * (n + 1)
for i in range(2, n + 1):
	j, p = i, smallest_prime_factor[i]
	while smallest_prime_factor[j] == p:
		j //= p
		num_divisors[i] += 1
	num_divisors[i] *= num_divisors[j]

ans = sum(1 for i in range(2, n + 1) if num_divisors[i] == num_divisors[i - 1])
print(ans)