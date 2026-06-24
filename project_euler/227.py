def get_adjacent(n: int, x: int, roll: int) -> int:
	return (x + n - 1) % n if roll == 1 else (x + 1) % n if roll == 6 else x

def calculate(n: int) -> float:
	adj = [dict[int, int]() for _ in range(n // 2 + 1)]

	for l in range(1, n // 2 + 1):
		x, y = 0, l
		for roll1 in range(1, 7):
			for roll2 in range(1, 7):
				nx = get_adjacent(n, x, roll1)
				ny = get_adjacent(n, y, roll2)
				if nx > ny:
					nx, ny = ny, nx
				new_l = ny - nx
				new_l = min(new_l, n - new_l)
				if new_l not in adj[l]:
					adj[l][new_l] = 0
				adj[l][new_l] += 1

	dp = [0.0] * (n // 2 + 1)

	round = 0
	while True:
		error = 0.0
		for l in range(1, n // 2 + 1):
			ans = 0.0
			for new_l, count in adj[l].items():
				ans += dp[new_l] * count
			ans = ans / 36.0 + 1.0
			error += abs(ans - dp[l])
			dp[l] = ans

		round += 1

		if round % 1000 == 0:
			print(f"round = {round}, error = {error} ans = {dp[n // 2]}")

		if error < 1e-10:
			break

	return dp[n // 2]

print(f"{calculate(100):.10g}")