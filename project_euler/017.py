unit_place = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
tens_place = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
teen = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

def number_to_words(n):
	s = str(n)
	length = len(s)

	if length == 1:
		return unit_place[n]
	
	if length == 2:
		if n < 20:
			return teen[n - 10]
		return tens_place[n // 10] + " " + unit_place[n % 10]
	
	if length == 3:
		if n % 100 == 0:
			return unit_place[n // 100] + " hundred"
		return unit_place[n // 100] + " hundred and " + number_to_words(n % 100)
	
	if length == 4:
		if n % 1000 == 0:
			return unit_place[n // 1000] + " thousand"
		return unit_place[n // 1000] + " thousand " + number_to_words(n % 1000)
	
def number_letter_count(n):
	return len(number_to_words(n).replace(" ", ""))

print(342, number_letter_count(342))
print(115, number_letter_count(115))

N = 1000

ans = 0
for n in range(1, N + 1):
	ans += number_letter_count(n)
print(ans)