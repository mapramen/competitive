import sys

a = (map(int, line.split(',')) for line in sys.stdin.readlines())
a = list(zip(*a))

n = len(a)
dp = [[0] * n for _ in range(n + 1)]

for i in range(1, n + 1):
	x = float('inf')
	for j in range(n):
		x = min(x, dp[i - 1][j]) + a[i - 1][j]
		dp[i][j] = x

	x = float('inf')
	for j in range(n - 1, -1, -1):
		x = min(x, dp[i - 1][j]) + a[i - 1][j]
		dp[i][j] = min(dp[i][j], x)

print(min(dp[n]))