N = 1000

for a in range(1, N // 3 + 1):
	for b in range(a + 1, N - a - N // 3 + 1):
		c = N - a - b
		if c > b and a * a + b * b == c * c:
			print(a * b * c, a, b, c)