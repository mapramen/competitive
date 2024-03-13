from math import gcd, sqrt
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

def is_square(n):
  if n < 0:
    return False
  
  if n == 0 or n == 1:
    return True
  
  s = int(sqrt(n))
  return s * s == n

def rho_floyd(n):
  r = randint(1, n - 1)
  f = lambda z : (z * z + r) % n
  
  x = randint(1, n)
  y = x
  g = 1

  while g == 1:
    x = f(x)
    y = f(f(y))
    g = gcd(abs(x - y), n)
  
  return g

def rho_brent(n):
  r = randint(1, n - 1)
  f = lambda z : (z * z + r) % n
  
  x = randint(1, n)
  g = 1
  q = 1
  xs = x
  y = x

  m = 128
  l = 1

  while g == 1:
    y = x
    for _ in range(1, l):
      x = f(x)
    k = 0
    while k < l and g == 1:
      xs = x
      for _ in range(1, min(m, l - k)):
        x = f(x)
        q = (q * abs(y - x)) % n
      g = gcd(q, n)
      k = k + m
    l = l * 2

  if g == n:
    while True:
      xs = f(xs)
      g = gcd(abs(xs - y), n)
      if g > 1:
        break

  return g

def prime_factorization(n):
  if n == 1:
    return []
  
  if is_square(n):
    return prime_factorization(int(sqrt(n)))
  
  if is_prime(n):
    return [n]
  
  g = 1
  while g == 1 or g == n:
    g = rho_brent(n)

  prime_factors = prime_factorization(g)
  for p in prime_factors:
    while n % p == 0:
      n = n // p

  return prime_factors + prime_factorization(n)

def solve(n):
  if n == 1:
    return (1, 1)
  
  prime_factors = prime_factorization(n)
  prime_factors = sorted(list(set(prime_factors)))
  
  ans = []
  for p in prime_factors:
    k = 0
    while n % p == 0:
      n = n // p
      k = k + 1
    ans.append((p, k))

  return ans

if __name__ == "__main__":
  while True:
    n = int(input())
    if n == 0:
      break
    ans = solve(n)
    formatted_ans = ' '.join([f"{p}^{k}" for p, k in ans])
    print(formatted_ans)
    