def day_of_the_week(year, month, day):
	t = [0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4]
	year -= month < 3
	return (year + year//4 - year//100 + year//400 + t[month-1] + day) % 7

def counting_sundays():
	# January 1, 1901 was a Tuesday
	sundays = 0
	for year in range(1901, 2001):
		for month in range(1, 13):
			if day_of_the_week(year, month, 1) == 0:
				sundays += 1
	return sundays

print(day_of_the_week(1900, 1, 1))

print(counting_sundays())