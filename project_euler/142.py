from math import sqrt

def is_perfect_square(n):
	return n > 0 and n == int(n ** 0.5) ** 2

a = 3
while True:
	for b in range(2, a):
		if not is_perfect_square(a ** 2 - b ** 2):
			continue

		for c in range(int(sqrt(a ** 2 - b ** 2)) + 1, b):
			D = a ** 2 + b ** 2 + c ** 2
			if D % 2 != 0:
				continue
			D //= 2

			x = D - c ** 2
			y = D - b ** 2
			z = D - a ** 2

			if is_perfect_square(x - y) and is_perfect_square(x - z) and is_perfect_square(y - z):
				print(f"x + y + z = {x + y + z}, x = {x}, y = {y}, z = {z}")
				break
	a += 1