def sum(n):
	return n * (n + 1) / 2

def sumOfMultiples(d, n):
	return d * sum(n // d)

N = 1000
print(sumOfMultiples(3, N - 1) + sumOfMultiples(5, N - 1) - sumOfMultiples(15, N - 1))