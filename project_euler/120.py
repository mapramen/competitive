def solve(n):
	oddm = (n + 1) // 2
	evenm = n // 2
	return oddm * (4 * oddm + 1) * (oddm - 1) // 3 + 4 * evenm * (evenm + 1) * (evenm - 1) // 3

print(solve(1000))