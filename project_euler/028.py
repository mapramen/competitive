def number_spiral_diagonals(n):
	n = (n + 1) // 2
	return 4 * n * (8 * n ** 2 - 9 * n + 7) // 6 - 3

print(5, number_spiral_diagonals(5))
print(1001, number_spiral_diagonals(1001))