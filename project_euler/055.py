def is_palindrome(n):
	s = str(n)
	return s == s[::-1]

def is_lychrel(n):
	for i in range(50):
		n += int(str(n)[::-1])
		if is_palindrome(n):
			return False
	return True

ans = sum(1 for n in range(1, 10000) if is_lychrel(n))
print(ans)