import sys
import re
import z3

if __name__ == '__main__':
	hails = []
	for line in sys.stdin:
		a = list(map(int, list(filter(None, re.split(r';|,\s|\n|@', line)))))
		hails.append(a)

	n = 3

	px, py, pz, vx, vy, vz = z3.Ints("px py pz vx vy vz")

	s = z3.Solver()
	for i in range(n):
		pxi, pyi, pzi, vxi, vyi, vzi = hails[i]
		tsi = z3.Int("t" + str(i))
		
		s.add(px + vx * tsi == pxi + vxi * tsi)
		s.add(py + vy * tsi == pyi + vyi * tsi)
		s.add(pz + vz * tsi == pzi + vzi * tsi)
	
	s.check()

	ans = s.model().evaluate(px + py + pz)
	print(ans)