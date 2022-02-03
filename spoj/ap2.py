if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    x, y, s = map(int, input().split())
    
    n = (2 * s) // (x + y)
    
    d = (y - x) // (n - 5)
    a = x - 2 * d

    print(n)
    for i in range(0, n):
      print(a + i * d, end=' ')
    print()