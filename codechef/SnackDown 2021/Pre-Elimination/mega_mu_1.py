def Solve():
  n = int(input())
  a = list(map(int, input().split()))

  dp = {(0, 0): 1}

  for ax in a:
    dpx = {}
    for x in range(max(0, ax - 1), ax + 1):
      for (y, p), v in dp.items():
        if x != 0 and y > x:
          continue

        ny = x if x > 0 else y
        np = p ^ (ax - x)
        if (ny, np) not in dpx:
          dpx[(ny, np)] = 0
        dpx[(ny, np)] += v
    dp = dpx

  return sum([v if p == 0 else -v for (y, p), v in dp.items()]) == 0

if __name__ == "__main__":
  for _ in range(0, int(input())):
    print(f'{"YES" if Solve() else "NO"}')