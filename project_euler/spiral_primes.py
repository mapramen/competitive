def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

total_count = 0
prime_count = 0

n = -1
while n < 3 or prime_count / total_count >= 0.1:
	n += 2
	total_count += 4 if n > 1 else 1
	prime_count += sum(1 for i in range(4) if is_prime(n * n - i * (n - 1)))
	print(n, total_count, prime_count, prime_count / total_count)