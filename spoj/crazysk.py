if __name__ == "__main__":
	t = int(input())
	for _ in range(t):
		x, n = map(int, input().split())
		ans = x + (x - 1) // (n - 1)
		print(ans)