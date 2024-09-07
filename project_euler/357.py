N = 10**8

is_prime = [True] * (N + 2)

is_prime[0] = is_prime[1] = False

for i in range(2, int(N ** 0.5) + 1):
	if not is_prime[i]:
		continue
	for j in range(i * i, N + 2, i):
		is_prime[j] = False

is_valid = [True] * (N + 1)
for i in range(1, int(N ** 0.5) + 1):
	for j in range(i * i, N + 1, i):
		if not is_prime[i + j // i]:
			is_valid[j] = False

count = sum(is_valid)
s = sum(i for i in range(1, N + 1) if is_valid[i])
print(count, s)