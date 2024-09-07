from math import comb

def calculate(n, m, l):
	return sum(pow(-1, i) * comb(m, i) * pow(n - i, l) for i in range(m + 1))

def solve(l):
	return calculate(16, 3, l) - sum(calculate(15, 2, i) for i in range(l))

print(format(solve(3), 'X'))
print(format(solve(16), 'X'))