from time import sleep


def solve(n):
	sum_of_proper_divisors = [0] * (n + 1)
	for i in range(1, n + 1):
		for j in range(i * 2, n + 1, i):
			sum_of_proper_divisors[j] += i

	ans = (0, 0)
	for i in range(1, n + 1):
		j = i
		S = set()
		while (len(S) == 0 or j not in S) and j >= i and j <= n:
			S.add(j)
			j = sum_of_proper_divisors[j]
		
		if j == i and len(S) > ans[0]:
			ans = (len(S), i)
			print(ans)

	return ans

print(solve(1000000))
