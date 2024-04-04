def get_continued_fraction_kth_term(k):
	if k == 1:
		return 2
	return 2 * k // 3 if k % 3 == 0 else 1

def get_nth_continued_fraction(n):
	p, q = 1, 0
	for k in range(n, 0, -1):
		p, q = get_continued_fraction_kth_term(k) * p + q, p
	return (p, q)

for n in range(101):
	p, q = get_nth_continued_fraction(n)
	print(n, p, q, sum(int(d) for d in str(p)))