from functools import reduce

def get_nth_digit(n):
	length = 1
	lower_bound = 1
	upper_bound = 9

	while length * (upper_bound - lower_bound + 1) < n:
		n -= length * (upper_bound - lower_bound + 1)
		length += 1
		lower_bound = 10 * lower_bound
		upper_bound = 10 * upper_bound + 9

	number = lower_bound + (n - 1) // length
	return int(str(number)[(n - 1) % length])

ans = reduce(lambda x, y: x * y, (get_nth_digit(10 ** i) for i in range(7)), 1)

print(ans)