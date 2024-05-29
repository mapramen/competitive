def get_counts(n, k):
	m = n * k

	counts = [0] * (m + 1)
	counts[0] = 1

	for _ in range(k):
		for i in range(m, -1, -1):
			count = 0
			for j in range(max(0, i - n), i):
				count += counts[j]
			counts[i] = count
	
	return counts

cnt_a = get_counts(4, 9)
cnt_b = get_counts(6, 6)

combinations = 0
sum_cnt_b = 0
for i in range(len(cnt_a)):
	combinations += cnt_a[i] * sum_cnt_b
	sum_cnt_b += cnt_b[i]

ans = combinations / (sum(cnt_a) * sum(cnt_b))
print(round(ans, 7))