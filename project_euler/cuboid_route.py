from math import sqrt

def get_count(c):
	ans = 0
	for x in range(c + 1, 3 * c + 1):
		y = sqrt(x * x - c * c)
		if y > 2 * c:
			break
		if not y.is_integer():
			continue
		y = int(y)
		mina = max(1, y - c)
		maxa = min(c, y - 1, y // 2)
		ans += maxa - mina + 1
	return ans

def solve(m):
	n, ans = 1, 0
	while ans < m:
		ans += get_count(n)
		print(n, ans)
		n += 1
	return n

solve(1000000)