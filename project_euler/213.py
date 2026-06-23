import numpy as np

def calculate(n: int, k: int) -> float:
	a = np.zeros((n * n, n * n), dtype=float)

	for x in range(n):
		for y in range(n):
			neighbors = [(x + dx, y + dy) for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)] if 0 <= x + dx < n and 0 <= y + dy < n]
			for nx, ny in neighbors:
				a[nx * n + ny][x * n + y] = 1 / len(neighbors)

	dp = np.eye(n * n, dtype=float)

	while k > 0:
		if k % 2 == 1:
			dp = np.dot(dp, a)
		a = np.dot(a, a)
		k //= 2

	return np.sum(np.prod(1.0 - dp, axis=1))

print(f"{calculate(30, 50):.6f}")