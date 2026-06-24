from functools import cache

@cache
def calculate(remainder: int, mask: int) -> int:
	if mask.bit_count() == 20:
		return 1 if remainder == 0 else 0
	
	ans = 0
	for d in range(10):
		if mask == 0 and d == 0:
			continue

		if (mask & (1 << d)) == 0:
			ans += calculate((remainder * 10 + d) % 11, mask | (1 << d))
		elif (mask & (1 << (d + 10))) == 0:
			ans += calculate((remainder * 10 + d) % 11, mask | (1 << (d + 10)))
	return ans

print(calculate(0, 0))