import functools

@functools.cache
def dp(n):
	if n < 0:
		return 0
	
	if n == 0:
		return 1
	
	ans = 0
	for i in range(1, n + 1):
		ans += dp(i - 1) * dp(n - i)
	
	return ans

if __name__ == "__main__":
	while True:
		n = int(input())

		if n == -1:
			break
		
		print(dp(n))