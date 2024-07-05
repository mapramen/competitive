import functools

@functools.cache
def solve_red(n):
	if n < 0:
		return 0
	if n <= 1:
		return 1
	return solve_red(n - 2) + solve_red(n - 3) + solve_red(n - 2)

@functools.cache
def solve_green(n):
	if n < 0:
		return 0
	if n <= 2:
		return 1
	return solve_green(n - 3) + solve_green(n - 4) + solve_green(n - 5) + solve_green(n - 3)

@functools.cache
def solve_blue(n):
	if n < 0:
		return 0
	if n <= 3:
		return 1
	return solve_blue(n - 4) + solve_blue(n - 5) + solve_blue(n - 6) + solve_blue(n - 7) + solve_blue(n - 4)

def solve(n):
	return solve_red(n) + solve_green(n) + solve_blue(n) - 3

print(5, solve(5))
print(50, solve(50))