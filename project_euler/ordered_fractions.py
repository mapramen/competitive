a, b = 2, 5
c, d = 3, 7

k = (10**6 - b) // d
a += k * c
b += k * d

print(a, b)