import functools

@functools.cache
def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

@functools.cache
def is_paired_prime(p, q):
	return is_prime(int(str(p) + str(q))) and is_prime(int(str(q) + str(p)))

def dfs(m, candidates, i, clique, limit = None):
	if len(candidates) + len(clique) < m or limit and sum(clique) >= limit:
		return None

	if len(clique) == m:
		return (sum(clique), list(clique))
	
	candidates = set(j for j in candidates if all(is_paired_prime(j, k) for k in clique) if j < i)

	ans = None
	for j in candidates:
		clique.add(j)
		result = dfs(m, candidates, j, clique, limit)
		if result and (not ans or result < ans):
			ans = result
			limit = ans[0]
		clique.remove(j)
	
	return ans

def prime_pair_sets(m):
	n = 2
	primes = []

	ans = None
	while not ans or n <= ans[0]:
		if not is_prime(n):
			n += 1
			continue

		candidates = set(p for p in primes if is_paired_prime(n, p))

		result = dfs(m, candidates, n, {n}, None if not ans else ans[0])
		if result and (not ans or result < ans):
			ans = result
			print(ans)

		primes.append(n)
		n += 1

	return ans

print(prime_pair_sets(5))