from itertools import combinations

square_digits = [(0, 1), (0, 4), (0, 9), (1, 6), (2, 5), (3, 6), (4, 9), (6, 4), (8, 1)]

def is_digit_present(S, digit):
	return digit in S if digit != 6 and digit != 9 else 6 in S or 9 in S

def are_digits_present(S1, S2, digit1, digit2):
	return is_digit_present(S1, digit1) and is_digit_present(S2, digit2) or is_digit_present(S1, digit2) and is_digit_present(S2, digit1)

def is_valid(S1, S2):
	return all(are_digits_present(S1, S2, digit1, digit2) for digit1, digit2 in square_digits)

ans = sum(1 for S1 in combinations(range(10), 6) for S2 in combinations(range(10), 6) if S1 <= S2 and is_valid(S1, S2))
print(ans)