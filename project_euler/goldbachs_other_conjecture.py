N = 10001

is_prime = [True] * N
is_prime[0] = is_prime[1] = False
for i in range(2, N):
	if i * i > N:
		break

	if not is_prime[i]:
		continue

	for j in range(i * i, N, i):
		is_prime[j] = False

valid = [False] * N
for prime in (i for i in range(2, N) if is_prime[i]):
	for j in range(1, N):
		i = prime + 2 * j * j
		if i >= N:
			break
		valid[i] = True

ans = min(i for i in range(2, N) if i % 2 == 1 and not valid[i] and not is_prime[i])
print(ans)