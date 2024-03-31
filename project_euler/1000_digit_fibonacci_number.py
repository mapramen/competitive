import functools

@functools.cache
def fibonacci(n):
	if n <= 2:
		return 1
	return fibonacci(n - 1) + fibonacci(n - 2)

NUMBER_OF_DIGITS = 1000

n = 1
while True:
	fibonacci_number = fibonacci(n)
	if len(str(fibonacci_number)) == NUMBER_OF_DIGITS:
		print(n)
		break
	n += 1