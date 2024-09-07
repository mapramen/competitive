import math, functools

print(functools.reduce(lambda x, y: x * y // math.gcd(x, y), range(2, 24)))