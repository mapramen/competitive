def fibbinary(n):
	if n == 0:
		return 0
	
	a = [0, 1, 1]

	while a[-2] + a[-1] <= n:
		a.append(a[-2] + a[-1])

	ans = 0
	for i in range(len(a) - 1, 0, -1):
		if a[i] <= n:
			n -= a[i]
			ans += 2 ** (i - 2)

	return ans

def solve(n):
	x, y, ans = 0, n, 0
	while x <= y:
		mid = (x + y) // 2
		if fibbinary(mid) <= n:
			ans = mid
			x = mid + 1
		else:
			y = mid - 1
	return ans

print(solve(2**30))