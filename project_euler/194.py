from math import comb, perm

def add_edge(adj: list[list[int]], u: int, v: int) -> None:
	adj[u].append(v)
	adj[v].append(u)

def get_a_adj() -> list[list[int]]:
	adj = [list[int]() for _ in range(8)]
	add_edge(adj, 1, 2)
	add_edge(adj, 1, 4)
	add_edge(adj, 1, 5)
	add_edge(adj, 2, 3)
	add_edge(adj, 2, 7)
	add_edge(adj, 3, 4)
	add_edge(adj, 3, 7)
	add_edge(adj, 4, 5)
	add_edge(adj, 5, 6)
	add_edge(adj, 6, 7)
	return adj

def get_b_adj() -> list[list[int]]:
	adj = [list[int]() for _ in range(8)]
	add_edge(adj, 1, 2)
	add_edge(adj, 1, 4)
	add_edge(adj, 1, 5)
	add_edge(adj, 2, 7)
	add_edge(adj, 3, 4)
	add_edge(adj, 3, 7)
	add_edge(adj, 4, 5)
	add_edge(adj, 5, 6)
	add_edge(adj, 6, 7)
	return adj

def search_color_combinations(adj: list[list[int]], colors: list[int], n: int, i: int, total_colors: int) -> int:
	if i > n:
		return 1 if len(set(colors[1:])) == total_colors else 0
	
	mask = (1 << total_colors) - 1
	for j in adj[i]:
		if colors[j] != 0:
			# print(f"{i} <-> {j}: {colors[j]}")
			mask &= ~(1 << (colors[j] - 1))

	ans = 0
	while mask:
		lowest_bit = mask & -mask
		color = (lowest_bit).bit_length()
		colors[i] = color
		# print(f"mask = {mask:b} color[{i}] = {color}")
		ans += search_color_combinations(adj, colors, n, i + 1, total_colors)
		mask &= ~lowest_bit
		colors[i] = 0
	return ans

def get_color_combinations(c: int, mod: int, adj: list[list[int]]) -> int:
	n = len(adj) - 1
	
	colors = [0] * (n + 1)
	colors[1] = 1
	colors[2] = 2

	return sum(comb(c - 2, i - 2) * search_color_combinations(adj, colors, n, 3, i) for i in range(3, min(c, n) + 1)) % mod

def calculate(n: int, m: int, c: int, mod: int = 10 **8) -> int:
	comb_a = get_color_combinations(c, mod, get_a_adj())
	comb_b = get_color_combinations(c, mod, get_b_adj())
	return (comb(n + m, m) * pow(comb_a, n, mod) * pow(comb_b, m, mod) * perm(c, 2)) % mod

print(calculate(1, 0, 3))
print(calculate(0, 2, 4))
print(calculate(2, 2, 3))
print(calculate(25, 75, 1984))