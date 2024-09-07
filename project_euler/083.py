from heapq import heappop, heappush
import sys

directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

a = [list(map(int, line.split(','))) for line in sys.stdin.readlines()]

n, m = len(a), len(a[0])
d = [[float('inf')] * m for _ in range(n)]
heap = []

def check_and_push(x, y, dxy):
	if x < 0 or x >= n or y < 0 or y >= m:
		return
	dxy += a[x][y]
	if dxy < d[x][y]:
		d[x][y] = dxy
		heappush(heap, (dxy, x, y))

check_and_push(0, 0, 0)
while heap:
	dxy, x, y = heappop(heap)
	for dx, dy in directions:
		check_and_push(x+dx, y+dy, dxy)

print(d[n-1][m-1])