def cubic_permutations(m):
	limit = 1
	n = 1
	ans = None

	while not ans:
		d = {}
		while n ** 3 < limit:
			cube = n ** 3
			s = ''.join(sorted(str(cube)))
			d.setdefault(s, []).append(cube)
			n += 1
		limit *= 10
		ans = min((min(cubes) for cubes in d.values() if len(cubes) == m), default=None)
	
	return ans

print(cubic_permutations(5))