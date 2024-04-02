def calculate(n):
	count = {}
	for a in range(1, n + 1):
		for b in range(a + 1, n + 1):
			p = a + b + (a * a + b * b) ** 0.5
			if p > n:
				break

			if p.is_integer():
				p = int(p)
				count[p] = count.get(p, 0) + 1
	return max(count, key=count.get)

print(calculate(1000))