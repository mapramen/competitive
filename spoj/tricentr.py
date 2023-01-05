from cmath import sqrt
import numpy as np

def area(a, b, c):
  A = [
    [0,    1,    1,    1], 
    [1,    0, c * c, b * b], 
    [1, c * c,    0, a * a], 
    [1, b * b, a * a,    0],
  ]
  return sqrt(-np.linalg.det(A) / 16).real

if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    h = list(map(float, input().split()))
    ar = 1 / (4 *  area(1 / h[1], 1 / h[2], 1 / h[3]))
    R = 2 * ar ** 2 / (h[1] * h[2] * h[3])
    OH = sqrt(9 * R ** 2 - 4 * ar ** 2 * (h[1] ** -2 + h[2] ** -2 + h[3] ** -2)).real
    GH = 2 * OH / 3

    ar *= 9
    GH *= 3
    print("%.3f %.3f" % (ar, GH))