def contribution(n):
	return (n + 1) * (n + 2) // 2

def solve(n):
	v = []
	while n > 0:
		v.append(n % 7)
		n //= 7

	if not v:
		v = [0]

	v = v[::-1]

	length = len(v)
	less_than_count, equal_count = 0, 1
	for i in range(length):
		less_than_count += equal_count * contribution(v[i] - 1) * (contribution(6) ** (length - i - 1))
		equal_count *= (v[i] + 1)

	return less_than_count

for l in range(1, 10):
	n = 7 ** l
	print(l,n, solve(n))  