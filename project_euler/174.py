def hollow_square_laminae(k, n):
	cnt = [0] * (n + 1)

	for y in range(2, n + 1, 2):
		for x in range(y + 2, n // y + 1, 2):
			cnt[x * y] += 1

	return sum(1 for x in range(1, n + 1) if 0 < cnt[x] <= k)

print(hollow_square_laminae(10, 10**6))