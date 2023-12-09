import sys

def predict_next_in_sequence(a):
	diffs = [a]
	
	while any(diffs[-1]):
		diffs.append([diffs[-1][i + 1] - diffs[-1][i] for i in range(len(diffs[-1])-1)])
	
	diffs[-1].append(0)

	for n in range(len(diffs) - 2, -1, -1):
		diffs[n].append(diffs[n][-1] + diffs[n + 1][-1])

	return diffs[0][-1]

if __name__ == '__main__':
	ans = 0
	for line in sys.stdin:
		a = list(map(int, line.split()))
		ans += predict_next_in_sequence(a)
	print(ans)