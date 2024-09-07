import functools

@functools.cache
def dp(k, n):
	if n < 0:
		return 0
	if n == 0:
		return 1
	return dp(k, n - 1) + dp(k, n - k)

def solve(n):
	return dp(2, n) + dp(3, n) + dp(4, n) - 3

print(5, solve(5))
print(50, solve(50))