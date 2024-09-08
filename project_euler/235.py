def agp(n, a, b, r):
	return a * (r ** n - 1) / (r - 1) + b * (n * r ** (n + 1) - (n + 1) * r ** n + 1) / (r - 1) ** 2

n, a, b = 5000, 900, -3
target = -600000000000

lower, upper = 1, 1.125
while upper - lower > 1e-12:
	mid = (lower + upper) / 2
	calculated_value = agp(n, a, b, mid)

	print(f"lower = {lower}, upper = {upper}, mid = {mid}, calculated_value = {calculated_value}")
	
	if calculated_value > target:
		lower = mid
	else:
		upper = mid

print(f"Answer is {(lower + upper) / 2:.12f}")