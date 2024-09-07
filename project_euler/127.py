from math import gcd

def solve(n):
	rad = list(range(n))

	for p in range(2, n):
		if rad[p] != p:
			continue
		
		for i in range(p, n, p):
			while rad[i] % p == 0:
				rad[i] //= p
			rad[i] *= p

	rad_to_nums = {}
		
	ans = 0
	for c in range(1, n):
		if rad[c] not in rad_to_nums:
			rad_to_nums[rad[c]] = []
		rad_to_nums[rad[c]].append(c)
		
		if rad[c] == c:
			continue

		limit = c // rad[c]
		for r in range(1, limit + 1):
			if r not in rad_to_nums or gcd(c, r) != 1:
				continue
			for a in rad_to_nums[r]:
				if 2 * a > c:
					break
				if r * rad[c - a] < limit:
					ans += c

	return ans

print(solve(120000))