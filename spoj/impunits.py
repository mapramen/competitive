from math import gcd

if __name__ == '__main__':
	while True:
		n = int(input())
		if n == -1:
			break

		a, b = 1, 1
		for _ in range(n - 1):
			c, d = map(int, input().split())
			a, b = a * c, b * d

		g = gcd(a, b)
		print(a // g, b // g)