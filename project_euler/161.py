from functools import cache

TRIOMINO_POSITIONS = [
	[(0, 0), (1, 0), (1, -1)],
	[(0, 0), (1, 0), (1, 1)],
	[(0, 0), (0, 1), (1, 1)],
	[(0, 0), (0, 1), (1, 0)],
	[(0, 0), (1, 0), (2, 0)],
	[(0, 0), (0, 1), (0, 2)],
]

@cache
def calculate(n: int, m: int, mask: int = 0) -> int:
	if n == 0:
		return 1 if mask == 0 else 0
	
	if (mask & ((1 << m) - 1)).bit_count() == m:
		return calculate(n - 1, m, (mask >> m))
	
	ans = 0

	# lowest unset bit
	lowest_bit = ((~mask) & (mask + 1)).bit_length() - 1

	for triomino in TRIOMINO_POSITIONS:
		triomino_mask = 0
		
		for dx, dy in triomino:
			if dx >= n:
				triomino_mask = None
				break
			
			x, y = dx, lowest_bit + dy
			if y < 0 or y >= m:
				triomino_mask = None
				break
			
			triomino_mask |= (1 << (x * m + y))
		
		if triomino_mask == None or (mask & triomino_mask) != 0:
			continue

		ans += calculate(n, m, mask ^ triomino_mask)
	
	return ans

print(calculate(12, 9))