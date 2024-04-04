import sys

dp = [list(map(int, line.split(','))) for line in sys.stdin.readlines()]

n, m = len(dp), len(dp[0])

for j in range(1, m):
	dp[0][j] += dp[0][j - 1]

for i in range(1, n):
	dp[i][0] += dp[i - 1][0]
	for j in range(1, m):
		dp[i][j] += min(dp[i - 1][j], dp[i][j - 1])

print(dp[n-1][m-1])