import functools

@functools.cache
def collatz_length(n):
	if n == 1:
		return 1
	if n % 2 == 0:
		return 1 + collatz_length(n // 2)
	return 1 + collatz_length(3 * n + 1)

print(max([(collatz_length(i), i) for i in range(1, 1000000)]))