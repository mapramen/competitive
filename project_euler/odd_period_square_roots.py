from math import floor, gcd, sqrt

def calculate_square_root_period_length(n):
	x = int(sqrt(n))
	if x * x == n:
		return 0
	
	a, b, c = 1, -x, 1

	dictionary = {}
	i = 0
	while True:
		d = gcd(abs(a), gcd(abs(b), abs(c)))
		a, b, c = a // d, b // d, c // d

		if (a, b, c) in dictionary:
			return i - dictionary[(a, b, c)]
		
		dictionary[(a, b, c)] = i

		a, b, c = a * c, -c * b, a * a * n - b * b

		x = floor((a * sqrt(n) + b) / c)
		b -= c * x

		i += 1

	return -1

ans = sum(1 for i in range(2, 10001) if calculate_square_root_period_length(i) % 2 == 1)
print(ans)