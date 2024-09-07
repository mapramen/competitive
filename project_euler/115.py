import functools

@functools.cache
def dp(m, n):
	if n < 0:
		return 0
	if n < m:
		return 1
	if n == m:
		return 2
	return 1 + dp(m, n - 1) + sum(dp(m, n - i - 1) for i in range(m, n))

def counting_block_combinations(m, limit):
	n = 0
	while dp(m, n) <= limit:
		n += 1
	print(n, dp(m, n))

counting_block_combinations(3, 1e6)
counting_block_combinations(10, 1e6)
counting_block_combinations(50, 1e6)