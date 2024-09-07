import functools
import itertools

@functools.cache
def is_prime(n):
	if n < 2:
		return False
	
	p = 2
	while p * p <= n:
		if n % p == 0:
			return False
		p += 1

	return True

def is_prime_permutation(n):
	if not is_prime(n):
		return False
	
	permutations = (int(''.join(p)) for p in itertools.permutations(str(n)))
	permutations = sorted(set(p for p in permutations if p > n and is_prime(p)))

	for i, p1 in enumerate(permutations):
		for p2 in permutations[i + 1:]:
			if n + p2 == 2 * p1:
				print(p1 - n, n, p1, p2)
				return True
			
	return False

ans = [n for n in range(1000, 10000) if is_prime_permutation(n)]
print(ans)