from fractions import Fraction

def is_prime(n: int) -> bool:
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

def calculate(n: int, s: str) -> Fraction:
	prime_chars = ['P' if is_prime(i + 1) else 'N' for i in range(n)]
	
	adj = [[y for y in range(x - 1, x + 2, 2) if 0 <= y < n] for x in range(n)]
	 
	dp = [Fraction(1, n)] * n
	 
	for _ in range(len(s)):
		new_dp = [Fraction(0)] * n
		
		for x in range(n):
			new_prob = (Fraction(2, 3) if prime_chars[x] == s[_] else Fraction(1, 3)) * dp[x] / len(adj[x])
			for y in adj[x]:
				new_dp[y] += new_prob
				
		dp = new_dp
	
	result = Fraction(0)
	for x in range(n):
		result += dp[x]
	return result

print(calculate(500, "PPPPNNPPPNPPNPN"))