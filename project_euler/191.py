import functools

@functools.cache
def prize_strings(n, last_absences = 2, lates = 1):
	if last_absences < 0 or lates < 0:
		return 0
	
	if n == 0:
		return 1
	
	return prize_strings(n - 1, 2, lates) + prize_strings(n - 1, last_absences - 1, lates) + prize_strings(n - 1, 2, lates - 1)

print(prize_strings(4))
print(prize_strings(30))