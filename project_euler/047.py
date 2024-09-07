N = 200001

a = [i for i in range(N)]
dp = [0] * N
for i in range(2, N):
	if a[i] != i:
		continue

	for j in range(i, N, i):
		dp[j] += 1
		while a[j] % i == 0:
			a[j] //= i

for i in range(1, N - 4):
	if dp[i:i+4] == [4] * 4:
		print(i)
		break