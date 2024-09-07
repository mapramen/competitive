import math

ans = 0

n = 1
while True:
	lower_bound = math.ceil(10 ** (1 - 1 / n))
	if lower_bound == 10:
		break
	ans += sum(1 for i in range(lower_bound, 10) if len(str(i ** n)) == n)
	n += 1

print(ans)