import functools

@functools.cache
def stern_diatomic(n):
	if n < 2:
		return n
	if n % 2 == 0:
		return stern_diatomic(n // 2)
	return stern_diatomic(n // 2) + stern_diatomic(n // 2 + 1)

def f(n):
	return stern_diatomic(n + 1)

for l in range(26):
	print(f'10^{l}: {f(10 ** l)}')