def matrix_mult(A: list[list[int]], B: list[list[int]], mod: int) -> list[list[int]]:
	n, p, m = len(A), len(A[0]), len(B[0])

	C = [[0] * m for _ in range(n)]
	for i in range(n):
		for j in range(m):
			for k in range(p):
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod
	return C

def calculate(n: int, mod: int) -> int:
	a = [
		[0, 1, 1, 1, 0],
		[0, 1, 1, 0, 0],
		[2, 0, 0, 0, 2],
		[1, 0, 0, 0, 0],
		[1, 0, 0, 0, 1],
	]

	b = [
		[1, 0, 0, 0, 0],
		[0, 1, 0, 0, 0],
		[0, 0, 1, 0, 0],
		[0, 0, 0, 1, 0],
		[0, 0, 0, 0, 1],
	]

	n -= 1
	while n > 0:
		if n % 2 != 0:
			b = matrix_mult(b, a, mod)
		a = matrix_mult(a, a, mod)
		n = n // 2

	return (b[0][0] + b[0][1]) % mod

print(calculate(10**12, 10**8))