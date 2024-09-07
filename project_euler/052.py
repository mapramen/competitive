def is_permuted_multiple(n, m):
	for i in range(2, m + 1):
		if sorted(str(i * n)) != sorted(str(n)):
			return False
	return True

n = 1
while True:
	if is_permuted_multiple(n, 6):
		print(n)
		break
	n += 1