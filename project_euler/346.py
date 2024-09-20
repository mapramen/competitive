def solve(limit):
	S = set([1])
	
	for b in range(2, int(limit ** 0.5) + 1):
		n = b * b + b + 1
		while n < limit:
			S.add(n)
			n = n * b + 1

	return sum(S)

for length in range(1, 13):
	n = 10 ** length
	print(f"10**{length}: {solve(n)}")