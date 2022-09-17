def solve(s):
  l = len(s)
  if s[0] == '1':
    t = '9' * l
  else:
    t = '1' * (l + 1)
  return int(t) - int(s)

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    input()
    print(solve(input()))