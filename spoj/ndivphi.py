def is_prime(n):
  for i in range(2, n):
    if n % i == 0:
      return False
  return True

def solve(n):
  m = 1
  
  p = 2
  while m * p <= n:
    if is_prime(p):
      m *= p
    p += 1
  
  return m

if __name__ == "__main__":
  for _ in range(20):
    print(solve(int(input())))