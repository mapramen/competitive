def solve():
  n, m = map(int, input().split())
  diff = [[0] * (n + m + 1) for _ in range(n + 2)]

  A = list(map(int, input().split()))
  for i in range(1, n + 1):
    diff[0][i] = A[i - 1]

  for k in range(1, n + 1):
    for i in range(1, n - k + 1):
      diff[k][i] = diff[k - 1][i + 1] - diff[k - 1][i]

  for k in range(n, -1, -1):
    for i in range(n - k + 1, n + m + 1):
      diff[k][i] = diff[k][i - 1] + diff[k + 1][i - 1]

  for i in range(n + 1, n + m + 1):
    print(diff[0][i], end=' ')
  print()

if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    solve()