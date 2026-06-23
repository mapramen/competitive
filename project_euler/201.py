def calculate(a: list[int], k: int) -> int:
	dp = [[0] * (sum(a) + 1) for _ in range(k + 1)]

	dp[0][0] = 1
	for x in a:
		for i in range(k, 0, -1):
			for y in range(x, len(dp[i])):
				dp[i][y] += dp[i - 1][y - x]
		print(f"Processed {x ** 0.5:.0f}: {sum(dp[k])} ways to choose {k} numbers")

	return sum(x for (x, ways) in enumerate(dp[k]) if ways == 1)

# print(calculate([1, 3, 6, 8, 10, 11], 3))
print(calculate([i * i for i in range(1, 101)], 50))