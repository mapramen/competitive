ans = 0

a, b = 1, 1
for _ in range(1000):
		a, b = a + 2 * b, a + b
		if len(str(a)) > len(str(b)):
			ans += 1

print(ans)