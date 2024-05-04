def search(n, validations, S, a, k):
	sums = []
	for x, y, z in validations:
		if a[x] is not None and a[y] is not None and a[z] is not None:
			sums.append(a[x] + a[y] + a[z])

	if len(set(sums)) > 1:
		return
	
	if k == n:
		outer_indices = [x for x, _, __ in validations]
		if a[outer_indices[0]] == min(a[x] for x in outer_indices):
			S.add((sums[0], tuple((tuple((a[x], a[y], a[z])) for x, y, z in validations))))
		return
	
	x = k // 2 if k % 2 == 0 else n - 1 - k // 2
	candidates = [i for i in range(1, n + 1) if i not in a]

	for candidate in candidates:
		a[x] = candidate
		search(n, validations, S, a, k + 1)
		a[x] = None

def solve(n):
	m = n // 2
	a = [None] * n

	validations = []
	for i in range(m):
		j = (i + 1) % m
		k = n - 1 - i
		validations.append((k, i, j))

	S = set()
	search(n, validations, S, a, 0)
	S = sorted(S)
	print(*S, sep='\n')

	ans = [''.join((''.join(str(z) for z in y) for y in x)) for _, x in S]
	print(*ans, sep='\n')
	return max((x for x in ans if len(x) == 16))

print(solve(10))
