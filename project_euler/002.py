N = 4000000

a, b, s = 0, 2, 0
while b <= N:
	if b % 2 == 0:
		s += b
	a, b = b, a + 4 * b

print(s)