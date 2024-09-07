def is_bouncy_number(n):
	s = str(n)
	return any(s[i - 1] < s[i] for i in range(1, len(s))) and any(s[i - 1] > s[i] for i in range(1, len(s)))

count = 0

n = 0
while 100 * count != 99 * max(n, 1):
	n += 1
	if is_bouncy_number(n):
		count += 1

print(n)