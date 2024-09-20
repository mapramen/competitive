from queue import Queue

def is_prime(n):
	if n < 2:
		return False

	if n == 2 or n == 3:
		return True

	if n % 2 == 0:
		return False

	r, d = 0, n - 1
	while d % 2 == 0:
		r += 1
		d = d // 2

	bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	
	for a in bases:
		if a >= n:
			break

		x = pow(a, d, n)
		
		for _ in range(r - 1):
			x = (x * x) % n
		
		if x == 1 or x == n - 1:
			continue
		
		return False

	return True

def sum_of_digits(n):
	return sum(int(d) for d in str(n))

def is_harshad(n):
	return n % sum_of_digits(n) == 0

def generate_strong_right_truncatable_harshad_primes(n):
	Q = Queue()

	for d in range(1, 10):
		Q.put(d)

	while not Q.empty():
		x = Q.get()
		if x > n:
			break

		if is_prime(x):
			y = x // 10
			if y != 0 and is_prime(y // sum_of_digits(y)):
				yield x

		if not is_harshad(x):
			continue

		for d in range(10):
			Q.put(x * 10 + d)

def solve(n):
	return sum(x for x in generate_strong_right_truncatable_harshad_primes(n))

for length in range(1, 15):
	n = 10 ** length
	print(n, solve(n))