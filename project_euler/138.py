from math import sqrt

def negative_pell_solutions(n):
	x1, y1 = 0, 0
	while True:
		if (x1 * x1 + 1) % n == 0:
			z = sqrt((x1 * x1 + 1) // n)
			if z.is_integer():
				y1 = int(z)
				break
		x1 += 1

	x, y = x1, y1
	yield (x1, y1)

	while True:
		x, y = x * x1 ** 2 + n * x * y1 ** 2 + 2 * n * y * x1 * y1, y * x1 ** 2 + n * y * y1 ** 2 + 2 * x * x1 * y1
		yield (x, y)

def solve(k):
	count, ans = 0, 0

	for x, y in negative_pell_solutions(5):
		b = 2 * (x - 2 if x % 5 == 2 else x + 2) // 5
		l = y

		if b == 0:
			continue

		count += 1
		ans += l

		print(count, b, l, ans)

		if count == k:
			break

	return ans

print(solve(12))