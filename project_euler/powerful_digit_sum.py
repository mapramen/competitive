def digit_sum(n):
	return sum(int(d) for d in str(n))

ans = max((digit_sum(a**b), a, b) for a in range(100) for b in range(100))
print(ans)