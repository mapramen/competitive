global d = set()

def IsLoop(n, m):
    dx = set()
    while n != m:
        if (n, m) in dx or (n, m) in d:
            global d
            d = d.union(dx)
            return 1
        else:
            dx.add((n, m))
            m -= n
            n += n
            if n > m:
                n, m = m, n
    return 0

N = 11
for i in range(1, N):
    for j in range(1, N):
        print i, j, IsLoop(i, j)
