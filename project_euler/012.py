def number_of_divisors(n):
	ans = 1

	p = 2
	while p * p <= n:
		k = 0
		while n % p == 0:
			k += 1
			n //= p
		ans = (k + 1) * ans
		p += 1

	if n > 1:
		ans *= 2
	
	return ans

NUMBER_OF_DIVISORS_THRESHOLD = 500

n = 1
while True:
	triangular_number = n * (n + 1) // 2
	divisors_cnt = number_of_divisors(triangular_number)
	if number_of_divisors(triangular_number) > NUMBER_OF_DIVISORS_THRESHOLD:
		print(triangular_number)
		break
	n += 1
