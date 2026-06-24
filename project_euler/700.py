def calculate(euler: int, mask: int) -> int:
	sum = euler
	while euler > 1:
		mask %= euler
		euler -= mask
		sum += euler
	return sum

print(calculate(1504170715041707, 4503599627370517))
			