from math import floor

def f(x):
	x *= 10**-9
	return floor(2**(30.403243784-x**2))

a = [-10**9]

while True:
	x = f(a[-1])
	print(len(a), x)
	if x not in a:
		a.append(x)
		continue

	i = a.index(x)
	print(i, len(a))
	break