from math import comb

def non_bouncy_numbers(n):
	return comb(n + 9, 9) + comb(n + 10, 10) - 10 * n - 2

for n in range(1, 101):
	print(n, non_bouncy_numbers(n))