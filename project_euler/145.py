def count(n):
	if n % 4 == 1:
		return 0
	
	if n % 4 == 3:
		return 100 * pow(500, n // 4)
	
	return 20 * pow(30, n // 2 - 1)
	
def reversible_numbers(length):
	return sum(count(n) for n in range(1, length + 1))

print(reversible_numbers(9))  # 120