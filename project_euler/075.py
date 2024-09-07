from math import gcd

def similar_integer_right_triangles(limit):
	S = set()
	dp = [0] * (limit + 1)
	
	for m in range(2, int(pow(limit, 0.5)) + 1):
		for n in range(1, m):
			a = m * m - n * n
			b = 2 * m * n
			c = m * m + n * n
			l = a + b + c
			if l <= limit and gcd(a, b) == 1:
				S.add(l)
	
	for i in S:
		for j in range(i, limit + 1, i):
			if dp[j] < 2:
				dp[j] += 1

	return sum(1 for dpi in dp if dpi == 1)

print(similar_integer_right_triangles(1500000))  # 161667