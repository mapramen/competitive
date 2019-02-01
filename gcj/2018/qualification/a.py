import numpy as np
import math

for N in range(200, 201):
    ans = None

    for n in range(3, N + 1):
        for m in range(3, N + 1):
            if n * (m - 1) >= N or n * m < N:
                continue

            A = np.zeros((n, m))

            for x in range(1, n - 1):
                for y in range(1, m - 1):
                    for dx in range(-1, 2):
                        for dy in range(-1, 2):
                            A[x + dx][y + dy] += 1

            p = 0
            s = np.sum(A)

            k = int(math.ceil(1.0 * N / n))
            k = int(math.ceil(1.0 * k / m))
            l = int(math.floor(1000 / max(1, k)))

            for x in range(0, n):
                for y in range(0, m):
                    p += pow(1 - A[x][y] / s, l)

            p *= k

            p = 1 - p

            print N, n, m, k, l, p

            if ans == None or p > ans[2]:
                ans = (n, m, p)

    print N, ans
