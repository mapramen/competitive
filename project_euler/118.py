import functools
import itertools
from queue import Queue
import sys

def is_prime(n):
	if n < 2:
		return False

	if n == 2 or n == 3:
		return True

	if n % 2 == 0:
		return False

	r, d = 0, n - 1
	while d % 2 == 0:
		r += 1
		d = d // 2

	bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	
	for a in bases:
		if a >= n:
			break

		x = pow(a, d, n)
		
		for _ in range(r - 1):
			x = (x * x) % n
		
		if x == 1 or x == n - 1:
			continue
		
		return False

	return True

@functools.cache
def solve(limit, s):
	if not s:
		return 1
	
	ans = 0
	for l in range(1, len(s) + 1):
		for combination in itertools.combinations(s, l):
			b = "".join(map(str, set(s) - set(combination)))
			for permutation in itertools.permutations(combination):
				n = int("".join(map(str, permutation)))
				if n < limit and is_prime(n):
					ans += solve(n, b)
	return ans

print(solve(sys.maxsize, "".join(map(str, range(1, 10)))))