import itertools

def is_prime(n):
	return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

def get_prime_digit_replacements(s):
	numbers = (int(s.replace('*', str(i))) for i in range(1 if s[0] == '*' else 0, 10))
	return [n for n in numbers if is_prime(n)]

def prime_digit_replacements(m):
	n = 2
	while True:
		if not is_prime(n):
			n += 1
			continue

		s = str(n)
		digit_to_positions = {}
		for i, c in enumerate(s):
			digit_to_positions.setdefault(c, []).append(i)

		for positions in digit_to_positions.values():
			for r in range(1, len(positions) + 1):
				for positions_combination in itertools.combinations(positions, r):
					if n - 1 in positions_combination:
						continue
					s_new = ''.join('*' if i in positions_combination else c for i, c in enumerate(s))
					primes = get_prime_digit_replacements(s_new)
					if len(primes) == m:
						return n

		n += 1

print(prime_digit_replacements(8))