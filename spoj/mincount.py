if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n = int(input())
    n = n - 1
    k = n // 3
    print(3 * k * (k + 1) // 2 + (n % 3) * (k + 1))