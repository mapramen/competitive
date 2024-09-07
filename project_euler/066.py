from math import floor, gcd, sqrt

def reduce_continued_fraction(continued_fraction):
	continued_fraction = continued_fraction[::-1]
	numerator, denominator = 1, 0
	for x in continued_fraction:
		numerator, denominator = denominator + numerator * x, numerator
	return numerator, denominator

def get_fundamental_solution(n):
	x = int(sqrt(n))
	if x * x == n:
		return 0
	
	a, b, c = 1, -x, 1

	dictionary = {}
	continued_fraction = [x]
	i = 1
	while (a, b, c) not in dictionary:		
		dictionary[(a, b, c)] = i

		a, b, c = a * c, -c * b, a * a * n - b * b

		x = floor((a * sqrt(n) + b) / c)
		b -= c * x
		continued_fraction.append(x)

		d = gcd(abs(a), gcd(abs(b), abs(c)))
		a, b, c = a // d, b // d, c // d
		i += 1

	period = i - dictionary[(a, b, c)]
	if period % 2 == 0:
		continued_fraction.pop()
	else:
		continued_fraction += continued_fraction[dictionary[(a, b, c)]:-1]

	numerator, denominator = reduce_continued_fraction(continued_fraction)
	# print(n, continued_fraction, numerator, denominator)
	return numerator

def solve(n):
	max_x = 0
	for D in range(2, n + 1):
		x = get_fundamental_solution(D)
		if x > max_x:
			max_x = x
			print(f"D = {D}, x = {x}")

solve(1000)