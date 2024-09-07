import functools

@functools.cache
def fibonacci(n):
	if n == 0:
		return 0
	
	if n < 3:
		return 1
	
	if n % 2 == 0:
		k = n // 2
		return (2 * fibonacci(k + 1) - fibonacci(k)) * fibonacci(k)
	
	k = (n + 1) // 2
	return fibonacci(k) ** 2 + fibonacci(k - 1) ** 2

def fibonacci_golden_nugget(n):
	return fibonacci(2 * n) * fibonacci(2 * n + 1)

for n in range(1, 16):
	print(n, fibonacci_golden_nugget(n))