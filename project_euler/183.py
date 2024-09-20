import math

def calculate_part_count(n):
	x = math.floor(n / math.e)
	_, k = max((i * math.log(n / i), i) for i in range(x, x + 2))
	return k

def d(n):
	k = calculate_part_count(n)
	k //= math.gcd(n, k)
	while True:
		g = math.gcd(k, 10)
		if g == 1:
			break
		k //= g
	return n if k != 1 else -n

def solve(n):
	return sum(d(i) for i in range(5, n + 1))

for length in range(1, 5):
	n = 10 ** length
	print(n, solve(n))