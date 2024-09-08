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

def solve(n):
	if n >= 1:
		print(1, 1)
		if n == 1:
			return 1

	if n >= 2:
		print(2, 2)
		if n == 2:
			return 2

	cnt = 2
	r = 2
	while cnt < n:
		i = 2 + 3 * r * (r - 1)

		if is_prime(6 * r - 1) and is_prime(6 * r + 1) and is_prime(12 * r + 5):
			cnt += 1
			print(cnt, i)
			if cnt == n:
				return i
		
		i += 6 * r - 1

		if is_prime(6 * r + 5) and is_prime(6 * r - 1) and is_prime(12 * r - 7):
			cnt += 1
			print(cnt, i)
			if cnt == n:
				return i
		
		r += 1
			
print(solve(2000))