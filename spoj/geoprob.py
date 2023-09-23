if __name__ == "__main__":
  t = int(raw_input())
  for _ in range(0, t):
    b, c, d = raw_input().split(" ")
    b = int(b)
    c = int(c)
    d = int(d)
    print(2 * c - (b + d))
    