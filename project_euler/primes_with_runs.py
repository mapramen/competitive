import itertools
import more_itertools

def is_prime(n):
	if n < 2:
		return False

	if n == 2 or n == 3:
		return True

	if n % 2 == 0:
		return False

	r, d = 0, n - 1
	while d % 2 == 0:
		r += 1
		d = d // 2

	bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
	
	for a in bases:
		if a >= n:
			break

		x = pow(a, d, n)
		
		for _ in range(r - 1):
			x = (x * x) % n
		
		if x == 1 or x == n - 1:
			continue
		
		return False

	return True

def primes_with_runs(n):
	ans = 0
	for digit in range(0, 10):
		other_digits = list(range(0, 10))
		other_digits.remove(digit)
		for cnt in range(n, -1, -1):
			other_digit_combinations = itertools.combinations_with_replacement(other_digits, n - cnt)

			combinations = ([digit] * cnt + list(other_digit_combination) for other_digit_combination in other_digit_combinations)
			permutations = set(x for y in (more_itertools.distinct_permutations(combination) for combination in combinations) for x in y)

			numbers = (int(''.join(map(str, permutation))) for permutation in permutations if permutation[0] != 0)
			primes = list(number for number in numbers if is_prime(number))

			if primes:
				print(n, digit, cnt, len(primes), sum(primes), primes)
				ans += sum(primes)
				break
	return ans

print(primes_with_runs(10))