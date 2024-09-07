from math import gcd

def primitive_form(n):
	m = n
	powers = []
	
	p = 2
	while p * p <= n:
		k = 0
		while n % p == 0:
			n /= p
			k += 1
		if k > 0:
			powers.append(k)
		p += 1

	if n > 1:
		powers.append(1)

	#gcd of all powers
	g = 0
	for power in powers:
		g = gcd(g, power)
		
	return ((int)(m ** (1 / g)), g)

def distinct_powers(n):
	ans = set()

	for a in range(2, n + 1):
		x, g = primitive_form(a)
		for b in range(2, n + 1):
			ans.add((x, g * b))
	return len(ans)

print(5, distinct_powers(5))
print(100, distinct_powers(100))
print(1000, distinct_powers(1000)) 