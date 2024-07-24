import sys

def check(a):
	n = len(a)
	S = [set() for _ in range(n + 1)]

	S[0].add(0)
	for x in a:
		for i in range(n, 0, -1):
			for y in S[i - 1]:
				z = x + y
				if z in S[i]:
					return False
				S[i].add(z)

	for i in range(1, n + 1):
		if min(S[i]) <= max(S[i - 1]):
			return False
		
	return True

a = [list(map(int, line.split(','))) for line in sys.stdin.readlines()]

ans = sum(sum(ai) for ai in a if check(ai))
print(ans)