from fractions import Fraction

def calculate(n: int) -> int:
	dp = [set[Fraction]() for _ in range(n + 1)]

	dp[1].add(Fraction(1))

	ans = set[Fraction]()
	ans.add(Fraction(1))

	for i in range(2, n + 1):
		dp[i].add(Fraction(i))
		dp[i].add(Fraction(1, i))
		
		for x in range(1, i // 2 + 1):
			y = i - x
			for frac1 in dp[x]:
				for frac2 in dp[y]:
					for frac in [frac1 + frac2, 1 / (1 / frac1 + 1 / frac2)]:
						if frac not in ans:
							dp[i].add(frac)
		
		for frac in dp[i]:
			ans.add(frac)
		print(f"i = {i} dp = {len(dp[i])} ans = {len(ans)}")

	return len(ans)

print(calculate(18))