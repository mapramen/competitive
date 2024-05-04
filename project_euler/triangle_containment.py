import sys
import numpy as np

def check_triangle_containment(p0, p1, p2, p):
	x0, y0 = p0
	x1, y1 = p1
	x2, y2 = p2
	x, y = p

	A = np.array([[x1 - x0, x2 - x0], [y1 - y0, y2 - y0]])
	b = np.array([x - x0, y - y0])
	ans = np.linalg.solve(A, b)
	s, t = ans
	return 0 <= s <= 1 and 0 <= t <= 1 and s + t <= 1

def check_triangle(line):
	x0, y0, x1, y1, x2, y2 = map(int, line.split(','))
	return check_triangle_containment((x0, y0), (x1, y1), (x2, y2), (0, 0))

ans = sum(check_triangle(line) for line in sys.stdin.readlines())
print(ans)