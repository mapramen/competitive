from itertools import permutations

def get_valid_partitions(n):
	for a in range(1, n // 3 + 1):
		for b in range(a, (n - a) // 2 + 1):
			c = n - a - b
			if a <= b <= c:
				yield (a, b, c)

ans = set()
for (sa, sb, sc) in get_valid_partitions(9):
	for permutation in permutations('123456789'):
		a = int(''.join(permutation[:sa]))
		b = int(''.join(permutation[sa:sa+sb]))
		c = int(''.join(permutation[sa+sb:]))
		if a * b == c:
			print(f'{a} * {b} = {c}')
			ans.add(c)

print(sum(ans), ans)