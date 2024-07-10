import functools
from math import ceil

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

def get_initial_answer_threshold(limit):
	limit = 2 * limit - 1

	ans = 1
	
	i = 1
	while 3 ** i < limit:
		ans *= get_nth_prime(i)
		i += 1
	ans *= get_nth_prime(i)
	
	return ans

def solve(limit, ans_threshold, ans, i = 1):
	if limit % 2 == 0:
		limit += 1

	if limit == 1:
		return ans
	
	p = get_nth_prime(i)

	for j in range(3, limit + 1, 2):
		ans *= p
		if ans >= ans_threshold:
			break
		ansj = solve(ceil(limit / j), ans_threshold, ans, i + 1)
		if ansj >= ans_threshold:
			continue
		ans_threshold = ansj

	return ans_threshold

def diaphantine_reciprocals(limit):
	return solve(2 * limit - 1, get_initial_answer_threshold(limit), 1)

# print(diaphantine_reciprocals(10 ** 3))
print(diaphantine_reciprocals(4 * 10 ** 6))