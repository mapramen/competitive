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

  bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
  
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

def prime_factorization(n):
  ans = []

  i = 2
  while i * i <= n:
    while n % i == 0:
      ans.append(i)
      n = n // i
    i = i + 1

  if n != 1:
    ans.append(n)

  return ans

def pollard_rho_prime_factorization(n):
  if n == 1:
    return []

  if is_prime(n):
    return [n]

  d = 1
  while d == 1 or d == n:
    g = lambda z : (z * z + 1) % n
    
    x = randint(1, n)
    y = x
    d = 1

    while d == 1:
      x = g(x)
      y = g(g(y))
      d = gcd(abs(x - y), n)

  k = 0
  while n % d == 0:
    k += 1
    n = n // d

  return prime_factorization(d) * k + pollard_rho_prime_factorization(n)

def solve(n):
  prime_factors = pollard_rho_prime_factorization(n)
  prime_factors.sort()
  
  f, s, ans = 1, 1, 1
  for i in range(len(prime_factors)):
    if i != 0 and prime_factors[i] != prime_factors[i - 1]:
      f, s = 1, ans
    f = f * prime_factors[i]
    ans += f * s

  return ans - n

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n = int(input())
    print(solve(n))