import sys

A = [list(map(int, line.split())) for line in sys.stdin]

n = len(A)
dp = [0] * (1 << n)

for k in range(len(A)):
	new_dp = dp[:]
	for mask in range(1 << n):
		if bin(mask).count('1') != k:
			continue
		for i in range(n):
			if mask & (1 << i):
				continue
			new_mask = mask | (1 << i)
			new_dp[new_mask] = max(new_dp[new_mask], dp[mask] + A[k][i])
	dp = new_dp

print(max(dp))