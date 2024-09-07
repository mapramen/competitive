import functools

def square_digit_root(n):
	if n <= 1 or n == 89:
		return n
	return square_digit_root(sum(int(d)**2 for d in str(n)))

@functools.cache
def solve(n, square_sum = 0):
	if n == 0:
		return 1 if square_digit_root(square_sum) == 89 else 0
	return sum(solve(n - 1, square_sum + i**2) for i in range(10))
	
print(solve(7))