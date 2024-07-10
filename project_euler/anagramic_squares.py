from itertools import groupby, permutations
from math import sqrt

def get_squares(max_square_length):
	squares = []
	for n in range(1, int(sqrt(10 ** max_square_length)) + 1):
		square = n ** 2
		square_length = len(str(square))
		if square_length > max_square_length:
			continue
		squares.append(square)
	return squares

def get_characteristics(word1, word2):
	d = {}
	for c in word1:
		if c not in d:
			x = len(d)
			d[c] = str(x)

	return (''.join(d[c] for c in word1), ''.join(d[c] for c in word2))

words = sorted((name.strip('"').strip() for name in input().split(',')), key=lambda x: ''.join(sorted(x)))

# Group the words by their sorted letters
word_groups = groupby(words, key=lambda x: ''.join(sorted(x)))

max_square_length = 0
candidates = {}

# Iterate over the groups and print the words in each group
for key, group in word_groups:
	group = list(group)
	if len(group) == 1:
		continue
	max_square_length = max(max_square_length, len(key))
	for combination in permutations(group, 2):
		characteristics = get_characteristics(*combination)
		if characteristics not in candidates:
			candidates[characteristics] = 0

squares = get_squares(max_square_length)
squares = sorted(squares, key=lambda x: ''.join(sorted(str(x))))

square_groups = groupby(squares, key=lambda x: ''.join(sorted(str(x))))

for key, group in square_groups:
	group = list(group)
	if len(group) == 1:
		continue
	group = [str(square) for square in group]
	for combination in permutations(group, 2):
		characteristics = get_characteristics(*combination)
		if characteristics in candidates:
			candidates[characteristics] = max(candidates[characteristics], int(combination[0]))

print(*candidates.items(), sep='\n')

print(max(candidates.values()))