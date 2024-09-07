K = 3
N = 99

single_scores = list(range(1, 21)) + [25]

dp_without_doubles_out = [[0] * (N + 1) for _ in range(K + 1)]
dp_without_doubles_out[0][0] = 1

for single_score in single_scores:
	for multiplier in range(1, 4):
		if single_score == 25 and multiplier == 3:
			continue

		x, y = 0, multiplier * single_score
		while y <= N:
			for k in range(1, K + 1):
				dp_without_doubles_out[k][y] += dp_without_doubles_out[k - 1][x]
			x += 1
			y += 1

dp_with_doubles_out = [[0] * (N + 1) for _ in range(K + 1)]

for single_score in single_scores:
	x, y = 0, 2 * single_score
	while y <= N:
		for k in range(1, K + 1):
			dp_with_doubles_out[k][y] += dp_without_doubles_out[k - 1][x]
		x += 1
		y += 1

ans = 0
for score in range(1, N + 1):
	for k in range(1, K + 1):
		ans += dp_with_doubles_out[k][score]
print(ans)