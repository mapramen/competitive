import sys

def jacobsthal(n):
	if n < 1:
		return 0
	
	a, b = 0, 1
	for _ in range(2, n + 1):
		a, b = b, b + 2 * a
	
	return b

def calculate(n):
	return jacobsthal(n - 1)

if __name__ == "__main__":
	for line in sys.stdin:
		n = int(line)
		print(calculate(n))