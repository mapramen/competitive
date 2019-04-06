import math, random

t = int(input())

for _ in range(1, t + 1):
  n, m = map(int, input().split())
  
  a = list(map(int, input().split()))
  
  b = [0] * (m + 1)

  k = 0
  g = 0
  while k < m - 1:
    g = math.gcd(a[k], a[k + 1])
    if g != a[k]:
      break
    k = k + 1

  b[k + 1] = g
  x = g
  for i in range(k, -1, -1):
    x = a[i] // x
    b[i] = x

  x = g
  for i in range(k + 1, m):
    x = a[i] // x
    b[i + 1] = x

  c = list(set(b))
  c.sort()

  primeToLetterMap = dict()
  for i in range(len(c)):
    primeToLetterMap[c[i]] = chr(ord('A') + i)

  ans = [primeToLetterMap[x] for x in b]

  print("Case #{0}: {1}".format(_, ''.join(ans)))