import math

def solve_quadratic(a, b, c):
	d = int(math.sqrt(b**2 - 4*a*c))
	if (d - b) % (2 * a) == 0:
		return (d - b) // (2 * a)
	else:
		return (-b - d) // (2 * a)

if __name__ == "__main__":
	for _ in range(int(input())):
		x, y, S = map(int, input().split())
		
		A = x + y
		B = y - x
		
		n = solve_quadratic(A, B - 6 * A - 2 * S, 12 * S)
		d = B // (n - 6)
		a = x - 2 * d

		print(n)
		for i in range(n):
			print(a + i * d, end=" ")
		print()