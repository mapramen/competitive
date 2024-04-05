from time import sleep

def is_number_valid(pattern, n, length = None):
	if not length:
		length = len(pattern)

	s = str(n * n)
	if len(s) < length:
		return False

	return all(pattern[-i] == '_' or pattern[-i] == s[-i] for i in range(1, length + 1))

def is_exact_match(pattern, n):
	return len(pattern) == len(str(n * n)) and is_number_valid(pattern, n)

def dfs(pattern, s, length):
	if s:
		n = int(s)
		if is_exact_match(pattern, n):
			return n
		
		if len(str(n * n)) > len(pattern):
			return None

	ans = (dfs(pattern, c + s, length + 1) for c in '0123456789' if is_number_valid(pattern, int(c + s), length + 1))
	return min((x for x in ans if x is not None), default=None)

print(dfs('1_2_3_4_5_6_7_8_9_0', '', 0))