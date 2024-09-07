from math import comb

n, m = 7, 10
for k in range(1, n * m + 1):
	ans = n * (1 - comb((n - 1) * m, k) / comb(n * m, k))
	print(k, ans)