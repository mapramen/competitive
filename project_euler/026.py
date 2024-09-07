def cycle_length(n):
	remainder_to_index = {}

	remainder = 1
	index = 1

	while remainder != 0 and remainder not in remainder_to_index:
		remainder_to_index[remainder] = index
		remainder = (remainder * 10) % n
		index += 1

	return 0 if remainder == 0 else index - remainder_to_index[remainder]

print(max(range(1, 1000), key=cycle_length))