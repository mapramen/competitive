def is_prime(n: int) -> bool:
	if n < 2:
		return False

	if n == 2 or n == 3:
		return True

	if n % 2 == 0:
		return False

	r, d = 0, n - 1
	while d % 2 == 0:
		r += 1
		d = d // 2

	bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	
	for a in bases:
		if a >= n:
			break

		x = pow(a, d, n)
		
		for _ in range(r - 1):
			x = (x * x) % n
		
		if x == 1 or x == n - 1:
			continue
		
		return False

	return True

def next_prime(n: int) -> int:
	p = n + 1
	while not is_prime(p):
		p += 1
	return p

def matrix_mult(A: list[list[int]], B: list[list[int]], mod: int) -> list[list[int]]:
	n, p, m = len(A), len(A[0]), len(B[0])

	C = [[0] * m for _ in range(n)]
	for i in range(n):
		for j in range(m):
			for k in range(p):
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod
	return C
	
def fibonacci(n: int, mod: int) -> int:
	a = [[1, 1], [1, 0]]

	b = [[1, 0], [0, 1]]

	while n > 0:
		if n % 2 == 1:
			b = matrix_mult(b, a, mod)

		a = matrix_mult(a, a, mod)
		n //= 2

	return b[0][1] % mod

MOD = 1234567891011

a = next_prime(10**14)

sum = 0
for n in range(1, 100001):
	b = fibonacci(a, mod=MOD)
	sum = (sum + b) % MOD
	print(f"n = {n}, a = {a}, b = {b}, sum = {sum}")
	a = next_prime(a)
print(sum)