from math import sqrt

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n = int(input())
    square_root = 1
    while square_root * square_root != n:
      square_root = (square_root + n // square_root) // 2
    print(square_root)