def is_prime(n):
	if n < 2:
		return False
	
	p = 2
	while p * p <= n:
		if n % p == 0:
			return False
		p += 1

	return True

def prime_count(a, b):
	if b <= 1:
		return 0
	
	n = 0
	while is_prime(n * n + a * n + b):
		n += 1
	return n

def quadratic_primes(n):
	return max((prime_count(a, b), a, b, a * b) for a in range(1 - n, n) for b in range(-n, n + 1))

print(quadratic_primes(1000))