def hollow_square_laminae(n):
	ans = 0
	for y in range(1, n + 1):
		for x in range(y + 1, n // y + 1):
			if x % 2 != y % 2:
				continue
			a = (x + y) // 2
			b = (x - y) // 2
			if a % 2 != b % 2:
				continue
			ans += 1
	return ans

print(hollow_square_laminae(10**6))