N = 101

dp = [0] * N

dp[0] = 1
for d in range(1, N):
	for i in range (d, N):
		dp[i] += dp[i - d]

for i in range(N):
	print(i, dp[i] - 1)