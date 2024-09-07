from collections import deque

def count(n, a, b, c, d):
	Q = deque()
	Q.append((a, b, c, d))

	count = 0
	while Q:
		a, b, c, d = Q.popleft()
		p, q = a + c, b + d

		if q > n:
			continue

		count += 1
		Q.append((a, b, p, q))
		Q.append((p, q, c, d))
	return count

print(count(12000, 1, 3, 1, 2))
	