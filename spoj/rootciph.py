if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    a, b, c = map(int, input().split())
    print(a * a - 2 * b)
    