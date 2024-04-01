def digit_fifth_power(n):
	return sum(int(i)**5 for i in str(n))

print(sum(i for i in range(2, 400000) if i == digit_fifth_power(i))) 