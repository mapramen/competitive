def is_triangular_number(n):
	low, high, ans = 1, n, 1
	while low <= high:
		mid = (low + high) // 2
		triangle = mid * (mid + 1) // 2
		if triangle <= n:
			ans = triangle
			low = mid + 1
		else:
			high = mid - 1
	return ans == n

def is_pentagonal_number(n):
	low, high, ans = 1, n, 1
	while low <= high:
		mid = (low + high) // 2
		pentagon = mid * (3 * mid - 1) // 2
		if pentagon <= n:
			ans = pentagon
			low = mid + 1
		else:
			high = mid - 1
	return ans == n

n = 1
while True:
	hexagon = n * (2 * n - 1)
	if is_triangular_number(hexagon) and is_pentagonal_number(hexagon):
		print(hexagon)
	n += 1