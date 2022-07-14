from math import gcd
from random import randint

def is_prime(n):
  if n < 2:
    return False

  if n == 2 or n == 3:
    return True

  if n % 2 == 0:
    return False

  r, d = 0, n - 1
  while d % 2 == 0:
    r += 1
    d = d // 2

  bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
  
  for a in bases:
    if a >= n:
      break

    x = pow(a, d, n)
    
    for _ in range(r - 1):
      x = (x * x) % n
    
    if x == 1 or x == n - 1:
      continue
    
    return False

  return True

def solve(s):
  n = len(s)
  dp = [0] * (n + 1)
  dp[0] = 1

  for i in range(1, n + 1):
    ans = 0
    for j in range(1, i + 1):
      if is_prime(int(s[j - 1 : i])):
        ans += dp[j - 1]
    dp[i] = ans

  return dp[n]

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    print(solve(input()))