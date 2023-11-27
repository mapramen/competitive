import numpy as np

if __name__ == "__main__":
	t = int(input())

	for _ in range(t):
		line = input()
		if not line:
			line = input()

		n, m = map(int, line.split())

		Q = np.zeros((n, n), int)

		for _ in range(m):
			i, j = map(int, input().split())
			i -= 1
			j -= 1

			Q[i][j] -= 1
			Q[j][i] -= 1

			Q[i][i] += 1
			Q[j][j] += 1

		if n == 1:
			print(1)
		else:
			M = Q[1:, 1:]
			print(int(round(np.linalg.det(M))))