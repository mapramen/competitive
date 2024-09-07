def square_root_digital_sum(n):
	x = int(n ** 0.5)
	if x ** 2 == n:
		return 0
	
	from decimal import Decimal, getcontext
	getcontext().prec = 102
	return sum(int(d) for d in str(Decimal(n).sqrt())[:101] if d != '.')

ans = sum(square_root_digital_sum(n) for n in range(1, 101))
print(ans)