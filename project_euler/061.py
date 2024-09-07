coefficients = [[1, 1, 2], [1, 0, 1], [3, -1, 2], [2, -1, 1], [5, -3, 2], [3, -2, 1]]

def dfs(adjacency_list, x, visited, path):
	path.append(x)

	if len(path) == len(coefficients):
		k = min(i for i in range(len(coefficients)) if i not in visited)
		ans = list(path)
		path.pop()
		if (k, ans[0]) in adjacency_list[ans[-1]]:
			print(k, sum(int(str(ans[i]) + str(ans[0 if i == len(coefficients) - 1 else i + 1])) for i in range(len(coefficients))))
			return ans
		return None
	
	for (i, y) in adjacency_list[x]:
		if i in visited:
			continue
		visited.add(i)
		result = dfs(adjacency_list, y, visited, path)
		visited.remove(i)

	path.pop()

adjacency_list = {}
for i, [a, b, c] in enumerate(coefficients):
	numbers = (n * (a * n + b) // c for n in range(200))
	numbers = [n for n in numbers if n >= 1000 and n < 10000 and n % 100 > 9]
	for n in numbers:
		s = str(n)
		x, y = int(s[:2]), int(s[2:])
		adjacency_list.setdefault(x, []).append((i, y))

for x in adjacency_list:
	dfs(adjacency_list, x, set(), [])
