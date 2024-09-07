MOD = 10**10
ans = 0
for i in range(1, 1001):
	ans = (ans + pow(i, i, MOD)) % MOD
print(ans)