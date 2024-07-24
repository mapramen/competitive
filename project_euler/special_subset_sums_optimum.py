from queue import Queue
import sys

K = 7

S = [(sys.maxsize, None) for _ in range(K + 1)]

def is_possible(a):
	n = len(a)
	S = [set() for _ in range(n + 1)]

	S[0].add(0)
	for x in a:
		for i in range(n, 0, -1):
			for y in S[i - 1]:
				S[i].add(x + y)

	for i in range(1, n + 1):
		if min(S[i]) <= max(S[i - 1]):
			return False
		
	return True

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

Q = Queue()
Q.put(([], 1))

while not Q.empty():
	a, i = Q.get()

	a.append(i)
	if check(a):
		k = len(a)
		s = sum(a)
		if s < S[k][0]:
			S[k] = (s, a[:])
			print(*S, sep = '\n')
		Q.put((a[:], i + 1))
	a.pop()

	if len(a) >= K:
		continue

	minimum_possible_sum = sum(a) + (i + 1)
	if all(S[j][0] <= minimum_possible_sum for j in range(len(a) + 1, K + 1)):
		continue

	if not is_possible(a + [i]):
		continue

	Q.put((a[:], i + 1))

print(*S, sep = '\n')