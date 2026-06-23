def calculate_probability(n: int, k: int, q: float) -> float:
	dp = [0.0] * (k + 1)

	dp[0] = 1.0
	for x in range(1, n + 1):
		for i in range(k, -1, -1):
			dp[i] = dp[i] * (x / q) + (0 if i == 0 else dp[i - 1] * (1 - x / q))
	return dp[k]

def calculate_q(n: int, k: int, percent: int) -> float:
	low, high = 1.0 * n, 2.0 * n
	while high - low > 1e-12:
		mid = (low + high) / 2.0
		if 100 * calculate_probability(n, k, mid) <= percent:
			high = mid
		else:
			low = mid
	return (low + high) / 2.0

print(f"{calculate_q(50, 20, 2):.10f}")