import functools

@functools.cache
def dp(length, start = 0):
	if length == 0:
		return {(0, 0): 1}
	
	result = {}
	for (a, b), count in dp(length - 1).items():
		for digit in range(start, 10):
			new_sum = digit + a + b
			if new_sum > 9:
				continue
			key = (digit, a)
			result[key] = result.get(key, 0) + count
	return result

def count(length):
	return sum(count for _, count in dp(length, 1).items())

print(count(20))