from math import gcd, sqrt

def solve(limit):
	ans = 0
	for m in range(1, int(sqrt(limit / 2)) + 1):
		for n in range(1, m):
			if (m - n) % 2 == 0:
				continue

			a = m * m - n * n
			b = 2 * m * n
			c = m * m + n * n
			
			if a + b + c > limit:
				break
			
			if c % abs(a - b) != 0 or gcd(a, b, c) != 1:
				continue
			
			ans += limit // (a + b + c)
	return ans

print(solve(10**8 - 1))