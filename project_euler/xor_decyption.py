def decode(a, key):
	s = ''
	for i, c in enumerate(a):
		s += chr(c ^ ord(key[i % len(key)]))
	return s

a = list(map(int, input().split(',')))

for i in range(97, 123):
	for j in range(97, 123):
		for k in range(97, 123):
			key = chr(i) + chr(j) + chr(k)
			s = decode(a, key)
			if ' the ' in s:
				print(s)
				print(sum(ord(c) for c in s))
				exit()

