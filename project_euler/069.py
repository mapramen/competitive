def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

def totient_maximum(n):
	ans = 1

	p = 2
	while p * ans <= n:
		if is_prime(p):
			ans *= p
		p += 1

	return ans

print(totient_maximum(10**6))