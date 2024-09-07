def solve(limit):
	b, n = 1, 1
	while n <= limit:
		b, n = 3 * b + 2 * n - 2, 4 * b + 3 * n - 3
		print(b, n)
	# return b, n

	for n in range(1, limit + 1):
		for b in range(1, n + 1):
			if b * (b - 1) == n * (n - 1) // 2:
				print(b, n)
				break

print(solve(10**12))