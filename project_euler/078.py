def solve(mod):
	p = [1 % mod]
	pentagonals = []
	n, m = 1, 1

	while True:
		while True:
			k = (m + 1) // 2 if m % 2 == 1 else -m // 2
			pentagonal = k * (3 * k - 1) // 2
			if pentagonal > n:
				break
			pentagonals.append(pentagonal)
			m += 1

		ans = 0
		for i, pentagonal in enumerate(pentagonals):
			if i % 4 < 2:
				ans = (ans + p[n - pentagonal]) % mod
			else:
				ans = (ans + mod - p[n - pentagonal]) % mod

		p.append(ans)
		if ans == 0:
			break

		n += 1

	return n

print(solve(1000000))