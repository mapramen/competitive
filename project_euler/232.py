def DP(dp: list[list[float]], i: int, j: int) -> float:
	if j <= 0:
		return 1.0
	if i <= 0:
		return 0.0
	return dp[i][j]

def calculate(n: int) -> float:
	dp = [[0.0 for _ in range(n + 1)] for _ in range(n + 1)]

	dp[0] = [1.0] * (n + 1)

	for i in range(1, n + 1):
		for j in range(1, n + 1):
			k = 1
			max_prob = 0.0
			while True:
				p = 1.0 / (2 ** k)
				bet = int(2 ** (k - 1))
				prob = (p * DP(dp, i, j - bet) + (1 - p) * DP(dp, i - 1, j) + p * DP(dp, i - 1, j - bet)) / (1 + p)
				max_prob = max(max_prob, prob)
				if bet >= j:
					break
				k += 1
			dp[i][j] = max_prob
		
	return 0.5 * dp[n][n] + 0.5 * dp[n - 1][n]

print(f"{calculate(100):.8f}")