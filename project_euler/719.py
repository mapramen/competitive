def check(target: int, n: int) -> bool:
	if n < target:
		return False
	
	if n == target:
		return True
	
	s = str(n)
	for i in range(1, len(s)):
		x = int(s[0:i])
		if x > target:
			break
		if check(target - x, int(s[i:])):
			return True
	return False

def calculate(n: int) -> int:
	ans = 0
	for i in range(2, int(n ** 0.5) + 1):
		if i % 9 <= 1 and check(i, i * i):
			ans += i * i
			print(i * i)
	return ans
	
print(calculate(10 ** 12))