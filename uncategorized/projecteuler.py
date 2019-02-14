s = 1000
for a in range(1, s + 1):
    for b in range(a, s + 1):
        if 2 * a * b % s != 0:
            continue
        c = a + b - 2 * a * b / s
        if a + b + c == s and c > max(a, b):
            print a, b, c, a * b * c
