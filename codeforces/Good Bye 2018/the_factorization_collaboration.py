import math, random

n = int(input())
primeFactors = [n]

def RefinePrimeFactors(x):
  global primeFactors
  updatedPrimeFactors = []
  for p in primeFactors:
    g = math.gcd(p, x)
    updatedPrimeFactors.extend([g, p // g])
  primeFactors = list(set(updatedPrimeFactors))

for _ in range(50):
  x = n
  while math.gcd(x, n) != 1:
    x = random.randint(1, n)
  print('sqrt {0}'.format((x * x) % n))
  y = int(input())
  RefinePrimeFactors(x + y)

primeFactors.remove(1)

print('! {0} {1}'.format(len(primeFactors), ' '.join([str(primeFactor) for primeFactor in primeFactors])))