N = 30001

dp = [0] * N
for i in range(1, N):
	for j in range(i * 2, N, i):
		dp[j] += i

abundant = set(i for i in range(1, N) if dp[i] > i)

ans = sum(i for i in range(1, N) if not any(j in abundant and i - j in abundant for j in range(1, i)))
print(ans)