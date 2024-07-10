def sum_of_fits(degree, f):
	a = []

	sum_of_fit = 0
	for n in range(degree):
		a.append([])
		a[0].append(f(n + 1))

		for i in range(1, n + 1):
			a[i].append(a[i - 1][-1] - a[i - 1][-2])

		fit = 0
		for i in range(n, -1, -1):
			fit += a[i][-1]

		sum_of_fit += fit
		print(n + 1, fit, sum_of_fit)

	return sum_of_fit

sum_of_fits(10, lambda n: (n ** 11 + 1) // (n + 1))