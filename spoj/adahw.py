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
  if n < 10**9:
    return prime_factorization(n)

  if is_prime(n):
    return [n]

  d = 1
  while d == 1 or d == n:
    r = randint(1, n - 1)
    g = lambda z : (z * z + r) % n
    
    x = randint(1, n)
    y = x
    d = 1

    while d == 1:
      x = g(x)
      y = g(g(y))
      d = gcd(abs(x - y), n)

  while n % d == 0:
    n = n // d

  return prime_factorization(d) + pollard_rho_prime_factorization(n)

def solve(n):
  prime_factors = pollard_rho_prime_factorization(n)
  prime_factors = list(set(prime_factors))
  
  d, phi, m = 1, n, n
  for p in prime_factors:
    k = 0
    while m % p == 0:
      k += 1
      m = m // p

    d = d * (1 + k)

    phi = phi // p
    phi = phi * (p - 1)

  return phi * d - n

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n = int(input())
    print(solve(n))