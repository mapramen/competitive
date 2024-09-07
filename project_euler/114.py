import functools

@functools.cache
def dp(m, n):
	if n < 0:
		return 0
	if n < m:
		return 1
	if n == m:
		return 2
	return 1 + dp(m, n - 1) + sum(dp(m, n - i - 1) for i in range(m, n))

print(7, dp(3, 7))
print(50, dp(3, 50))