import functools

@functools.cache
def solve(a):
	if a == ():
		return 1
	
	if a[0] == 0:
		return solve(a[1:])
	
	if a[0] > 3:
		return 0
	
	ans = 0
	for x in range(3):
		if x > a[0]:
			break
		b = list(a[1:])
		if b:
			b[0] += 2 * (a[0] - x)
		if not b and x != a[0]:
			continue
		ans += solve(tuple(b))
	return ans

def f(n):
	a = []
	while n:
		a.append(n % 2)
		n //= 2
	return solve(tuple(a[::-1]))

for l in range(26):
	print(f'10^{l}: {f(10 ** l)}')