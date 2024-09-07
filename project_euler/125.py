from math import sqrt

def is_palindrome(n):
	return str(n) == str(n)[::-1]

def solve(n):
	S = set()
	
	for i in range(1, int(sqrt(n)) + 1):
		s = 0
		for j in range(i, int(sqrt(n)) + 1):
			s += j * j
			if s > n:
				break
			if j == i:
				continue
			if is_palindrome(s):
				S.add(s)
	
	print(sum(S))

solve(1E8)