import sys

digit_place_to_roman_letters = [
	['I', 'V', 'X'],
	['X', 'L', 'C'],
	['C', 'D', 'M']
]

char_to_decimal = {
	'I': 1,
	'V': 5,
	'X': 10,
	'L': 50,
	'C': 100,
	'D': 500,
	'M': 1000
}

subtractions = {
	('I', 'V'): 1,
	('I', 'X'): 1,
	('X', 'L'): 10,
	('X', 'C'): 10,
	('C', 'D'): 100,
	('C', 'M'): 100
}

def decimal_to_roman(decimal):
	ans = ''
	for i in range(3):
		one, five, ten = digit_place_to_roman_letters[i]
		d = decimal % 10
		
		if d <= 3:
			ans = one * d + ans

		if d == 4:
			ans = one + five + ans

		if 5 <= d <= 8:
			ans = five + one * (d - 5) + ans

		if d == 9:
			ans = one + ten + ans

		decimal //= 10
	ans += decimal * 'M'
	return ans

def roman_to_decimal(roman):
	ans = 0
	previous_char = None
	for char in roman:
		ans += char_to_decimal[char]
		if previous_char is not None and (previous_char, char) in subtractions:
			ans -= 2 * subtractions[(previous_char, char)]
		previous_char = char
	return ans

def calculate(roman):
	decimal = roman_to_decimal(roman)
	minimal_roman = decimal_to_roman(decimal)
	return len(roman) - len(minimal_roman)

ans = sum(calculate(line.strip()) for line in sys.stdin.readlines())
print(ans)