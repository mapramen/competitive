from math import ceil, log10, sqrt, pi, e

def factorial_length_approximation(n):
  return 1 if n < 2 else ceil((n + 0.5) * log10(n) + log10(sqrt(2 * pi)) - n * log10(e))

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    print(factorial_length_approximation(int(input())))