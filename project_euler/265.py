def check(n, S, s):
	candidates = (s[-(n - 1 -i):] + s[:i+1] for i in range(n - 1))
	candidates = [candidate for candidate in candidates if candidate not in S]

	for candidate in candidates:
		S.add(candidate)

	ans = len(S) == (1 << n)

	for candidate in candidates:
		S.remove(candidate)

	return ans

def dfs(n, S, s, i):
	if i == (1 << n):
		return int(s, 2) if check(n, S, s) else 0
		
	ans = 0
	for d in range(0, 2):
		t = s[-(n - 1):] + str(d)
		if t not in S:
			S.add(t)
			ans += dfs(n, S, s + str(d), i + 1)
			S.remove(t)
	return ans

def solve(n):
	s = '0' * n
	S = set([s])
	return dfs(n, S, s, n)

for n in range(1, 6):
	print(n, solve(n))