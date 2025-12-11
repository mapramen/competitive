import os

def dfs(adj, target, node):
	if node == target:
		return 1
	return sum(dfs(adj, target, neighbor) for neighbor in adj.get(node, []))

if __name__ == "__main__":
	adj = {}

	for line in os.sys.stdin:
		tokens = list(token.strip(":") for token in line.split())
		adj[tokens[0]] = tokens[1:]

	print(dfs(adj, "out", "you"))