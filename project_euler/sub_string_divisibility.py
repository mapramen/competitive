from itertools import permutations

primes = [2, 3, 5, 7, 11, 13, 17]

def interesting_pandigital_numbers(s = ''):
	length = len(s)

	if length > 3 and int(s[-3:]) % primes[length - 4] != 0:
		return
	
	if length == 10:
		yield int(s)
	
	for i in '0123456789':
		if i == '0' and length == 0:
			continue

		if i not in s:
			yield from interesting_pandigital_numbers(s + i)

print(sum(interesting_pandigital_numbers()))
	