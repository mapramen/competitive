import functools

@functools.cache
def F(n):
	ans = n * (n + 3) // 2

	i = 2
	while i <= n:
		x = n // i
		j = (n + x) // x
		ans -= (j - i) * F(x)
		i = j

	return ans

print(F(10**6) - 2)