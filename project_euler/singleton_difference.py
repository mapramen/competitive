def solve(limit):
	cnt = [0] * limit

	for a in range(1, limit):
		for b in range((a + 3) // 4, a):
			n = a * (4 * b - a)
			if n >= limit:
				break
			cnt[n] += 1

	return sum(1 for c in cnt if c == 1)

print(solve(10**2))
print(solve(50 * 10**6))