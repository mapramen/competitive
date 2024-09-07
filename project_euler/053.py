def count(n, m):
	val = 1
	r = 0

	while 2 * r <= n and val <= m:
		r += 1
		val = val * (n - r + 1) // r

	r -= 1

	ans = n + 1 - 2 * (r + 1) + (2 * r == n)
	return ans

ans = sum(count(n, 1000000) for n in range(1, 101))
print(ans)