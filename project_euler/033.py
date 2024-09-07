from functools import reduce
from math import gcd

def digit_cancelling_fraction(a, b):
	if a % 10 == 0 and b % 10 == 0:
		return None, None
	
	sa = str(a)
	sb = str(b)

	if sa[0] == sb[0]:
		return int(sa[1]), int(sb[1])
	
	if sa[0] == sb[1]:
		return int(sa[1]), int(sb[0])
	
	if sa[1] == sb[0]:
		return int(sa[0]), int(sb[1])
	
	if sa[1] == sb[1]:
		return int(sa[0]), int(sb[0])
	
	return None, None

def is_digit_cancelling_fraction(a, b):
	if a >= b:
		return False
	x, y = digit_cancelling_fraction(a, b)
	if x is None:
		return False
	return a * y == b * x

fractions = ((a, b) for a in range(10, 100) for b in range(a + 1, 100) if is_digit_cancelling_fraction(a, b))
p, q = reduce(lambda x, y: (x[0] * y[0], x[1] * y[1]), fractions)
g = gcd(p, q)
print((p // g, q // g))