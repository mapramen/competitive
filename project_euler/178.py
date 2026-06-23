from functools import cache

@cache
def calculate(n: int, mask: int, prev: int | None = None) -> int:
	if n == 0:
		return 1 if mask.bit_count() == 10 else 0

	if prev is None:
		return sum(calculate(n - 1, mask | (1 << i), i) for i in range(1, 10))
	
	return (0 if prev == 0 else calculate(n - 1, mask | (1 << (prev - 1)), prev - 1)) + \
	       (0 if prev == 9 else calculate(n - 1, mask | (1 << (prev + 1)), prev + 1))

print(sum(calculate(n, 0) for n in range(1, 41)))