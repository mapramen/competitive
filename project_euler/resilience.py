from functools import reduce
from heapq import heappop, heappush

def is_prime(n):
	return all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

def resilience(numerator, denominator):
	primes = []

	p = 2
	while True:
		if not is_prime(p):
			p += 1
			continue

		primes.append(p)
		phi_ratio = reduce(lambda x, y: x * (1 - 1 / y), primes, 1)
		if phi_ratio < numerator / denominator:
			print(primes)
			break

		p += 1

	phi_ratio = reduce(lambda x, y: x * (1 - 1 / y), primes, 1)

	Q = []
	S = set()

	heappush(Q, reduce(lambda x, y: x * y, primes, 1))
	S.add(reduce(lambda x, y: x * y, primes, 1))

	while True:
		n = heappop(Q)
		if phi_ratio < numerator / denominator * (1 - 1 / n):
			return n
		
		for p in primes:
			if n * p not in S:
				heappush(Q, n * p)
				S.add(n * p)
		
print(resilience(15499, 94744))