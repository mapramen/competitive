from math import ceil, floor, gcd

def solve(n, m):
	count = 3 * n * m
	for x in range(1, n + 1):
		for y in range(1, m + 1):
			g = gcd(x, y)
			a, b = x // g, y // g
			k_min = ceil(max((y - m) / a, -x / b))
			k_max = floor(min(y / a, (n - x) / b))
			count += k_max - k_min
	return count


for n in range(1, 51):
	print(n, solve(n, n))