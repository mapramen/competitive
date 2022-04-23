def Calculate(A, m):
  dp = [[0] * (m + 1) for _ in range(n + 1)]
  dp[0] = [1] * (m + 1)
  
  for i in range(1, n + 1):
    a, b = A[i - 1]
    
    for j in range(a, m + 1):
      dp[i][j] = dp[i - 1][j - a]
    
    for j in range(b + 1, m + 1):
      dp[i][j] = dp[i][j] - dp[i - 1][j - b - 1]

    for j in range(1, m + 1):
      dp[i][j] = dp[i][j] + dp[i][j - 1]
  
  return dp[n][m] - dp[n][m - 1]

if __name__ == "__main__":
  while True:
    n, m = map(int, input().split())

    if n == 0:
      break

    A = []
    for _ in range(n):
      a, b = map(int, input().split())
      A.append((a, b))

    print(Calculate(A, m))