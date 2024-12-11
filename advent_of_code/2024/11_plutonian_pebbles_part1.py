def solve(k, n):
	if k == 0:
		return 1
	
	if n == 0:
		return solve(k - 1, 1)

	s = str(n)
	l = len(s)
	
	if l % 2 == 0:
		return solve(k - 1, int(s[:l // 2])) + solve(k - 1, int(s[l // 2:]))
	
	return solve(k - 1, 2024 * n)


a = map(int, input().split())
ans = sum(solve(25, n) for n in a)
print(ans)