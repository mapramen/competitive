N = 2000001

is_prime = [True] * N

for p in range(2, N):
	if p * p > N:
		break

	if not is_prime[p]:
		continue

	for j in range(p * p, N, p):
		if is_prime[j]:
			is_prime[j] = False

print(sum(i for i in range(2, N) if is_prime[i]))