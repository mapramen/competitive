from functools import reduce
from math import floor
from operator import mul

def P(m):
	return reduce(mul, (pow(2 * i / (m + 1), i) for i in range(1, m + 1)), 1)

ans = 0
for m in range(2, 16):
	ansx = P(m)
	ans += floor(ansx)
	print(m, ansx, ans)