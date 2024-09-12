def solve_in_direction(A, f):
	n = len(A)
	m = len(A[0])

	running_max_sum = {}
	max_sum = 0

	for i in range(n):
		for j in range(m):
			k = f(i, j)
			if k not in running_max_sum:
				running_max_sum[k] = 0
			running_max_sum[k] = max(running_max_sum[k] + A[i][j], 0)
			max_sum = max(max_sum, running_max_sum[k])

	return max_sum

def solve(A):
	return max(
		solve_in_direction(A, lambda i, j: i),
		solve_in_direction(A, lambda i, j: j),
		solve_in_direction(A, lambda i, j: i + j),
		solve_in_direction(A, lambda i, j: i - j)
	)

N = 2000

a = [0] * (N * N + 1)
for k in range(1, 56):
	a[k] = (100003 - 200003 * k + 300007 * k**3) % 1000000 - 500000

for k in range(56, N * N + 1):
	a[k] = (a[k - 24] + a[k - 55] + 1000000) % 1000000 - 500000

A = [a[i * N+1:(i + 1) * N+1] for i in range(N)]

print(solve(A))  