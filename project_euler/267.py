def calculate_final_value(n: int, k: int, f: float) -> float:
	return ((1 + 2 * f) ** k) * ((1 - f) ** (n - k))

def is_possible(target: int, n: int, k: int) -> bool:
	low, high = 0.0, 1.0

	while high - low > 1e-12:
		mid1, mid2 = low + (high - low) / 3, high - (high - low) / 3
		value1, value2 = calculate_final_value(n, k, mid1), calculate_final_value(n, k, mid2)
		
		if value1 >= target or value2 >= target:
			return True
		
		if value1 < value2:
			low = mid1
		else:
			high = mid2

	return False

def calculate_min_heads(n: int, target: int) -> int:
	low, high, ans = 0, n, n
	while low <= high:
		mid = (low + high) // 2
		if is_possible(target, n, mid):
			ans = mid
			high = mid - 1
		else:
			low = mid + 1
	return ans

def calculate(n: int, target: int) -> float:
	h = calculate_min_heads(n, target)
	print(f"Minimum heads required: {h}")

	dp = [0.0] * (n + 1)
	dp[0] = 1.0

	for i in range(1, n + 1):
		for j in range(i, -1, -1):
			dp[j] = dp[j] / 2
			if j > 0:
				dp[j] += dp[j - 1] / 2

	probability = 0.0
	for j in range(h, n + 1):
		probability += dp[j]
	return probability
	
print(f"{calculate(1000, 10**9):.12f}")