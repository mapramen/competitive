def counting_rectangles(limit):
	n = 1

	ans = (limit * (limit - 1) // 2, limit * (limit + 1) // 2, (1, limit), limit)
	while True:
		p = n * (n + 1) // 2

		ans = min(ans, (abs(limit - p), p, (1, n), n))
		if limit <= p:
			break

		m = n
		while True:
			count = p * (m * (m + 1) // 2)
			ans = min(ans, (abs(count - limit), count, (n, m), n * m))
			if limit <= count:
				break
			m += 1
		
		n += 1
	
	return ans

print(counting_rectangles(2 * 10 **6))