import functools
from math import factorial

@functools.cache
def factorial_digit_sum(n):
	return sum(factorial(int(digit)) for digit in str(n))

def digit_factorial_chain(n):
	chain = set()
	while n not in chain:
		chain.add(n)
		n = factorial_digit_sum(n)
	return chain

ans = sum(1 for n in range(10**6) if len(digit_factorial_chain(n)) == 60)
print(ans)