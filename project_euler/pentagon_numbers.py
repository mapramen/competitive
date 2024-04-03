def pentagon_number(n):
	return n * (3 * n - 1) // 2

def is_pentagon_number(p):
	n = (1 + (1 + 24 * p) ** 0.5) / 6
	return n.is_integer()

pentagon_numbers = [0]

ans = None
j = 1

while True:
	pentagon_numbers.append(pentagon_number(j))
	
	if ans and pentagon_numbers[j] - pentagon_numbers[j - 1] >= ans:
		break

	for i in range(j - 1, 0, -1):
		S = pentagon_numbers[j] + pentagon_numbers[i]
		D = pentagon_numbers[j] - pentagon_numbers[i]


		if ans and D >= ans:
			break

		if is_pentagon_number(S) and is_pentagon_number(D):
			if not ans or D < ans:
				ans = D
			break
	
	j += 1

print(ans)