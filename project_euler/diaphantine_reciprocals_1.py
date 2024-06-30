def calculate_square_divisors_cnt(n):
	cnt = 1
	
	i = 2
	while i * i <= n:
		if n % i != 0:
			i += 1
			continue
		power = 0
		while n % i == 0:
			power += 1
			n //= i
		cnt *= 2 * power + 1
		i += 1
	
	if n > 1:
		cnt *= 3
	
	return cnt

def solve(limit):
	n = 1
	while True:
		cnt = calculate_square_divisors_cnt(n)
		cnt = (cnt + 1) // 2
		print(n, cnt)
		if cnt > limit:
			return n
		n += 1

print(solve(1000))