import random


def get_adjacent(n: int, x: int, roll: int) -> int:
	return (x + n - 1) % n if roll == 1 else (x + 1) % n if roll == 6 else x

def calculate(n: int) -> float:
	adj = [[dict[tuple[int,int], int]() for _ in range(n)] for _ in range(n)]

	for x in range(n):
		for y in range(x + 1, n):
			for roll1 in range(1, 7):
				for roll2 in range(1, 7):
					nx, ny = get_adjacent(n, x, roll1), get_adjacent(n, y, roll2)
					if nx > ny:
						nx, ny = ny, nx
					if (nx, ny) not in adj[x][y]:
						adj[x][y][(nx, ny)] = 0
					adj[x][y][(nx, ny)] += 1

	dp = [[0.0 for _ in range(n)] for _ in range(n)]
	
	# states = [(x, y) for x in range(n) for y in range(x + 1, n)]
	# print(states)

	round = 0
	while True:
		new_dp = [[dp[x][y] for y in range(n)] for x in range(n)]
		# random.shuffle(states)
		for x in range(n):
			for y in range(x + 1, n):
				ans = 0.0
				for (nx, ny), count in adj[x][y].items():
					ans += new_dp[nx][ny] * count
				new_dp[x][y] = ans / 36.0 + 1.0

		round += 1
		error = sum(abs(new_dp[x][y] - dp[x][y]) for x in range(n) for y in range(x + 1, n))
		dp = new_dp

		if round % 1000 == 0:
			print(f"round = {round}, error = {error} ans = {new_dp[0][n // 2]}")

		if error < 1e-10:
			break

	return new_dp[0][n // 2]

print(f"{calculate(100):.10g}")