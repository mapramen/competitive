def is_greater(mask1, mask2):
	while mask1 and mask2:
		bit1, bit2 = mask1 & -mask1, mask2 & -mask2

		mask1 ^= bit1

		if bit2 > bit1:
			continue

		mask2 ^= bit2
		
	return mask2 == 0

def should_be_tested(mask1, mask2):
	return mask1.bit_count() == mask2.bit_count() and is_greater(mask1, mask2) == is_greater(mask2, mask1)

def solve(n):
	all_subset_pairs_count, tested_pairs_count = 0, 0

	for mask1 in range(1, 1 << n):
		for mask2 in range(1, 1 << n):
			if mask2 > mask1 or mask1 & mask2:
				continue

			all_subset_pairs_count += 1
			
			if should_be_tested(mask1, mask2):
				tested_pairs_count += 1

	return all_subset_pairs_count, tested_pairs_count

print(4, solve(4))
print(7, solve(7))
print(12, solve(12))