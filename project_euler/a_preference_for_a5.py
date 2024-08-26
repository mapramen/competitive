dp = {}

def get_new_state(a, i):
	b = a[:]
	b[i] -= 1
	for j in range(i):
		b[j] += 1
	return b

def solve(a):
	while a[-1] == 0:
		a.pop()

	key = tuple(a)
	if key in dp:
		return dp[key]
	
	m = sum(a)
	
	ans = 0
	if m == 1:
		k = a.index(1)
		ans = 1 if k == 0 else 1 + solve(get_new_state(a, k))
	else:
		for i in range(len(a)):
			if a[i] == 0:
				continue
			ans += (a[i] / m) * solve(get_new_state(a, i))

	dp[key] = ans
	return ans

for n in range(1, 9):
	print(n, f"{solve([0] * (n - 1) + [1]):.6f}")