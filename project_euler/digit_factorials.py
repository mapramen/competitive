N = 2200001

dp = [0] * N

dp[0] = 1
for i in range(1, min(10, N)):
	dp[i] = i * dp[i - 1]

for i in range(10, N):
	dp[i] = dp[i // 10] + dp[i % 10]

ans = sum(i for i in range(10, N) if i == dp[i])
print(ans)