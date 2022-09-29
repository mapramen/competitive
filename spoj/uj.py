if __name__ == "__main__":
  while True:
    n, d = map(int, input().split())
    if n == 0:
      break
    print(n ** d)