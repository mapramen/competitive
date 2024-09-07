def name_score(name):
	return sum(ord(c) - 64 for c in name)

a = sorted(name.strip('"') for name in input().split(','))

print(sum((i + 1) * name_score(name) for i, name in enumerate(a)))