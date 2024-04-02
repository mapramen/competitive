def pandigital_multiple(n):
	s = ""

	i = 1
	while len(s) != 9 and len(s) == len(set(s)) and '0' not in s:
		s += str(n * i)
		i += 1

	return int(s) if len(s) == 9 and len(s) == len(set(s)) and '0' not in s else 0

ans = max(pandigital_multiple(i) for i in range(1, 100000))
print(ans)