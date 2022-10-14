from cmath import sqrt
import numpy as np

def volume(a):
  d = list(map(lambda x: x * x, a))
  A = [
    [0,    1,    1,    1,    1], 
    [1,    0, d[0], d[1], d[2]], 
    [1, d[0],    0, d[3], d[4]], 
    [1, d[1], d[3],    0, d[5]], 
    [1, d[2], d[4], d[5],   0]
  ]
  return sqrt(np.linalg.det(A) / 288).real

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
    a = list(map(int, input().split()))
    r = 3.0 * volume(a) / (area(a[0], a[1], a[3]) + area(a[1], a[2], a[5]) + area(a[2], a[0], a[4]) + area(a[3], a[4], a[5]))
    print("%.4f" % r)