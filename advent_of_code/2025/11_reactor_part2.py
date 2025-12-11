import os

dp = {}

def dfs(adj, compulsory_nodes, compulsory_visited_cnt, target, node):
	if node == target:
		return 1 if compulsory_visited_cnt == len(compulsory_nodes) else 0
	
	if node in compulsory_nodes:
		compulsory_visited_cnt += 1

	if (compulsory_visited_cnt, node) in dp:
		return dp[(compulsory_visited_cnt, node)]
	
	dp[(compulsory_visited_cnt, node)] = sum(dfs(adj, compulsory_nodes, compulsory_visited_cnt, target, neighbor) for neighbor in adj.get(node, []))
	return dp[(compulsory_visited_cnt, node)]

if __name__ == "__main__":
	adj = {}

	for line in os.sys.stdin:
		tokens = list(token.strip(":") for token in line.split())
		adj[tokens[0]] = tokens[1:]

	print(dfs(adj, compulsory_nodes=["fft", "dac"], compulsory_visited_cnt=0, target="out", node="svr"))