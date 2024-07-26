from math import ceil, log2

def solve(n, limit, a, ans):
	if a[-1] > n or ans >= limit:
		return limit
	
	if a[-1] == n:
		return ans
	
	x = a[-1]
	for i in range(1, len(a) + 1):
		a.append(a[-i] + x)
		limit = min(limit, solve(n, limit, a, ans + 1))
		a.pop()
		if limit == ans + 1:
			break

	return limit

def efficient_exponentation(n):
	return sum((solve(i, ceil(2 * log2(i)), [1], 0) for i in range(1, n + 1)))

print(efficient_exponentation(200))