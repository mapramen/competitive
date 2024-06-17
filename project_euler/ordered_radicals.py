def solve(n, m):
	a = list(range(n + 1))

	for i in range(2, n + 1):
		if a[i] != i:
			continue
		
		for j in range(i, n + 1, i):
			while a[j] % i == 0:
				a[j] //= i
			a[j] *= i

	b = [(a[i], i) for i in range(n + 1)]
	b = sorted(b)
	print(b[m])

solve(100000, 10000)