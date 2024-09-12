def solve(n, eps):
	ans = 0
	k = 0
	while True:
		ansx = 1 - (1 - (1 / 2 ** k)) ** n
		if ansx < eps:
			break
		ans += ansx
		print(f"n = {n}, k = {k}, ans = {ans}")
		k += 1
	return round(ans, 10)

print(solve(32, 1e-11))