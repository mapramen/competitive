import functools

@functools.cache
def sum_of_divisors(n):
	if n < 1:
		return 0
	
	ans = 1

	p = 2
	while p * p <= n:
		s = 1
		while n % p == 0:
			s = 1 + p * s
			n = n // p
		p += 1
		ans = ans * s
	
	if n > 1:
		ans = (1 + n) * ans

	return ans

@functools.cache
def sum_of_proper_divisors(n):
	return sum_of_divisors(n) - n

N = 10000

sum = 0
for a in range(1, N):
	b = sum_of_proper_divisors(a)
	if b != a and sum_of_proper_divisors(b) == a:
		print(a, b)
		sum += a

print(sum)