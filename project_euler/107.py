import sys

def find(parent, i):
	if parent[i] == i:
		return i
	parent[i] = find(parent, parent[i])
	return parent[i]

def union(parent, i, j):
	i = find(parent, i)
	j = find(parent, j)

	if i == j:
		return False
	
	if i > j:
		i, j = j, i

	parent[j] = i
	return True

a = [list(int(token) if token != '-' else sys.maxsize for token in line.strip().split(',')) for line in sys.stdin.readlines()]

parent = {i: i for i in range(len(a))}
edges = [(a[i][j], i, j) for i in range(len(a)) for j in range(len(a[i])) if a[i][j] != sys.maxsize and i < j]

edges.sort()

ans = 0
for w, i, j in edges:
	if not union(parent, i, j):
		ans += w

print(ans)