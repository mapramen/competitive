def is_divisible(n):
	a, b, c = 1, 1, 1

	S = set()
	while (a, b, c) not in S:
		S.add((a, b, c))

		d = (a + b + c) % n
		if d == 0:
			return True
		
		a, b, c = b, c, d

	return False

n, cnt = 1, 0
while True:
	if not is_divisible(n):
		cnt += 1
		print(f"{cnt}: {n}")
	
	if cnt == 124:
		break

	n += 2