from math import gcd

def phi(n):
	ans = n
	
	i = 2
	while i * i <= n:
		if n % i == 0:
			ans -= ans // i
			while n % i == 0:
				n //= i
		i += 1

	if n > 1:
		ans -= ans // n

	return ans

def modular_tetration(a, b, mod):
	print(f"a = {a}, b = {b}, mod = {mod}")
	if gcd(a, mod) != 1:
		raise ValueError("a and mod must be coprime")

	if mod == 1:
		return 0

	if b == 1:
		return a % mod
	
	return pow(a, modular_tetration(a, b - 1, phi(mod)), mod)

print(modular_tetration(1777, 1855, 10**8))