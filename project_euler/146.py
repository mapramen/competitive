import functools

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

present_list = [1, 3, 7, 9, 13, 27]

@functools.cache
def is_possible(p, r):
	return not any((r ** 2 + c) % p == 0 for c in present_list)

def check(primes, n):
	for p in primes:
		if p > n:
			break
		if not is_possible(p, n % p):
			return False
	
	global checking_count
	checking_count += 1
	
	n = n ** 2
	for c in range(1, 28):
		n += 1
		valid = is_prime(n)
		if valid and c not in present_list or not valid and c in present_list:
			return False
	return True

def solve(limit):
	primes = []
	for p in range(2, int(limit ** 0.25) + 1):
		if is_prime(p):
			primes.append(p)

	ans = 0
	for n in range(0, limit, 10):
		if check(primes, n):
			ans += n
			print(n, ans)
	print(f'Checking count: {checking_count}')

checking_count = 0
solve(150 * 10 ** 6)