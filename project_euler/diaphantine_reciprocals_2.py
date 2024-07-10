import functools
from math import ceil, log

@functools.cache
def is_prime(n):
	return all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

@functools.cache
def get_nth_prime(n):
	i = 2
	while True:
		if is_prime(i):
			n -= 1
			if n == 0:
				break
		i += 1
	return i

def solve(limit, ans_log_threshold, ans_log, i = 1):
	if limit == 1:
		return (ans_log, [])
	
	if limit % 2 == 0:
		limit += 1
	
	p = get_nth_prime(i)
	log_p = log(p)
	
	factors = []

	for j in range(3, limit + 1, 2):
		ans_log += log_p
		if ans_log > ans_log_threshold:
			break
		result_ans_log_j, result_factors_j = solve(ceil(limit / j), ans_log_threshold, ans_log, i + 1)
		if result_ans_log_j >= ans_log_threshold:
			continue
		ans_log_threshold = result_ans_log_j
		factors = [(p, (j - 1) // 2)] + result_factors_j

	return ans_log_threshold, factors

def diaphantine_reciprocals(limit):
	_, factors = solve(2 * limit - 1, limit, 0)
	ans = 1
	for factor, power in factors:
		ans *= factor ** power
	return ans

# print(diaphantine_reciprocals(10 ** 3))
print(diaphantine_reciprocals(4 * 10 ** 6))