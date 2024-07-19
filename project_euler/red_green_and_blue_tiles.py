import functools

@functools.cache
def solve(n):
	if n < 0:
		return 0
	if n == 0:
		return 1
	return solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4)	

print(5, solve(5))
print(50, solve(50))