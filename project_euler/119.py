from heapq import heappop, heappush

heap = []
for x in range(2, 100):
	heappush(heap, (x, x))

limit = 30
i = 0
while i < limit:
	y, x = heappop(heap)
	if y > 9 and sum(int(d) for d in str(y)) == x:
		i += 1
		print(i, y, x)
	heappush(heap, (y * x, x))
	