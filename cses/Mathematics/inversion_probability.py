from math import lcm

def inversion_probability(n, m):
	return (n - 1, 2 * m) if n <= m else (2 * n - (m + 1), 2 * n)
 
if __name__ == "__main__":
	n = int(input())
	a = list(map(int, input().split()))
 
	c = [inversion_probability(a[i], a[j]) for i in range(n) for j in range(i + 1, n)]
 
	den = lcm(*(x[1] for x in c))
	num = sum(x[0] * (den // x[1]) for x in c)

	p = (10**7 * num) // den
	r = (10**7 * num) % den
	d = p % 10
	p //= 10

	if d > 5 or (d == 5 and r > 0) or (d == 5 and r == 0 and p % 2 == 1):
		p += 1

	ans = p / 10**6
 
	print(f"{ans:.6f}")