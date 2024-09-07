K = 12000
N = 13000

dp = [set() for _ in range(N + 1)]

dp[1].add((0, 0))

for i in range(1, N):
	for j in range(2 * i, N, i):
		for x, y in dp[i]:
			dp[j].add((x + 1, y + j // i))

dict = {}

for i in range(2, N):
	for x, y in dp[i]:
		k = x + (i - y)
		if k > 1 and k <= K and k not in dict:
			dict[k] = i

print(sum(set(dict.values())))