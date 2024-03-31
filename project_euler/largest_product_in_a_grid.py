import sys

directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
a = [list(map(int, line.split())) for line in sys.stdin]

n, m = len(a), len(a[0])

maximum_product = 0
for direction in directions:
	dx, dy = direction
	for i in range(n):
		for j in range(m):
			product = 1
			for k in range(4):
				x, y = i + k * dx, j + k * dy
				if 0 <= x < n and 0 <= y < m:
					product *= a[x][y]
			maximum_product = max(maximum_product, product)

print(maximum_product)