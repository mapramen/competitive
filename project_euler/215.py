from functools import cache

def calculate_tile_length(n: int, m: int, mask: int, i: int) -> int:
	if i < 0 or i >= m:
		return 0
	
	length = 0
	while (mask & (1 << (length * m + i))) != 0:
		length += 1
	return 0 if length == n else length

@cache
def calculate_tile_mask(m: int, length: int, i: int) -> int:
	mask = 0
	for j in range(length):
		mask |= (1 << (j * m + i))
	return mask

@cache
def calculate(n: int, m: int, mask: int = 0) -> int:
	if n == 0:
		return 1 if mask == 0 else 0
	
	if (mask & (1 << m) - 1).bit_count() == m:
		return calculate(n - 1, m, mask >> m)
	
	# lowest unset bit
	lowest_bit = ((~mask) & (mask + 1)).bit_length() - 1

	previous_tile_length = calculate_tile_length(n, m, mask, lowest_bit - 1)
	next_tile_length = calculate_tile_length(n, m, mask, lowest_bit + 1)

	ans = 0
	for current_tile_length in range(2, 4):
		if current_tile_length > n or current_tile_length == previous_tile_length or current_tile_length == next_tile_length:
			continue

		cur_tile_mask = calculate_tile_mask(m, current_tile_length, lowest_bit)	
		ans += calculate(n, m, mask ^ cur_tile_mask)
	return ans

print(calculate(32, 10))