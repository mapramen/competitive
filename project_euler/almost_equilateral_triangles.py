limit = 1000000000

a, b = 2, 1
perimeter_sum = 0

while True:
	if a % 3 == 2:
		x = 2 * ((a - 2) // 3)
		y = x + 1
	else:
		x = 2 * ((a + 2) // 3)
		y = x - 1
	
	pertimeter = 2 * x + y
	print(a, b, x, y, pertimeter)
	
	if pertimeter > limit:
		break

	if x != 0 and y != 0:
		perimeter_sum += pertimeter

	a, b = 2 * a + 3 * b, a + 2 * b

print(perimeter_sum)