def solve(limit):
	cnt = [0] * (limit + 1)

	for i in range(1, limit + 1):
		for j in range(i, limit + 1, i):
			d = i + j // i
			
			if d % 4 != 0:
				continue
			d //= 4
			
			if d >= i:
				continue

			cnt[j] += 1

	return sum(1 for c in cnt if c == 10)

print(solve(10**6))