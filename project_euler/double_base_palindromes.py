def is_palindrome(s):
	return s == s[::-1]

def is_double_base_palindrome(n):
	decimal = str(n)
	binary = bin(n)[2:]
	return is_palindrome(decimal) and is_palindrome(binary)

def sum_double_base_palindromes(n):
	return sum(i for i in range(n) if is_double_base_palindrome(i))

print(sum_double_base_palindromes(1000000))