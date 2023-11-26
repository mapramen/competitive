if __name__ == "__main__":
	t = int(input())
	for _ in range(t):
		n, m = map(int, input().split())
		ans = max(n * ((m + 1) // 2), m * ((n + 1) // 2))
		print(ans)