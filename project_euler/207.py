def solve(a, b):
	x, p, q = 2, 0, 0
	while True:
		k = x * x - x
		q += 1
		if(x & (x - 1)) == 0:
			p += 1
		print(f"x = {x}, k = {k}, p = {p}, q = {q}, ratio = {p / max(1, q)}")
		if p * b < q * a:
			break
		x += 1
	return x * x - x

print(solve(1, 12345))