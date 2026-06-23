def calculate(A: str, B: str, n: int) -> int:
	dp = list[int]()
	dp.append(0)
	dp.append(len(A))
	dp.append(len(B))

	while dp[-1] < n:
		dp.append(dp[-1] + dp[-2])

	k = 0
	while dp[k] < n:
		k += 1

	while k >= 3:
		if n <= dp[k - 2]:
			k -= 2
		else:
			n -= dp[k - 2]
			k -= 1

	return int(A[n - 1] if k == 1 else B[n - 1])

A = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
B = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"

ans = sum(10 ** n * calculate(A, B, (127 + 19 * n) * 7 ** n) for n in range(18))

print(ans)