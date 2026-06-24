from functools import cache

@cache
def S(n: int,k: int) -> int:
	if k <= 55:
		return (100003 - 200003 * k + 300007 * k ** 3) % n
	else:
		return (S(n, k - 24) + S(n, k - 55)) % n
	
def find(parent: list[int], x: int) -> int:
	return x if parent[x] == x else find(parent, parent[x])

def union(parent: list[int], sz: list[int], x: int, y: int) -> None:
	x = find(parent, x)
	y = find(parent, y)
	
	if x == y:
		return
	
	if x > y:
		x, y = y, x

	parent[y] = x
	sz[x] += sz[y]
	
def calculate(n: int, k: int) -> int:
	parent = [i for i in range(n)]
	sz = [1] * n

	calls, success = 0, 0
	while sz[find(parent, k)] < 0.99 * n:
		calls += 1
		x = S(n, 2 * calls - 1)
		y = S(n, 2 * calls)

		if x != y:
			union(parent, sz, x, y)
			success += 1
		
	return success

print(calculate(1000000, 524287))