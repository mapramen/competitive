from cmath import sqrt
import numpy as np

if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    d = list(map(lambda x: x * x, map(int, input().split())))
    A = [
      [0,    1,    1,    1,    1], 
      [1,    0, d[0], d[1], d[2]], 
      [1, d[0],    0, d[3], d[4]], 
      [1, d[1], d[3],    0, d[5]], 
      [1, d[2], d[4], d[5],   0]
    ]
    print("%.4f" % sqrt(np.linalg.det(A) / 288).real)