N = 1000000

is_prime = [True] * N
is_prime[0] = is_prime[1] = False
for i in range(2, N):
	if i * i > N:
		break

	if not is_prime[i]:
		continue

	for j in range(i * i, N, i):
		is_prime[j] = False

def is_circular_prime(n):
	if not is_prime[n]:
		return False
	
	s = str(n)
	for i in range(1, len(s)):
		if not is_prime[int(s[i:] + s[:i])]:
			return False
	return True

print([i for i in range(N) if is_circular_prime(i)])

print(sum(1 for i in range(2, N) if is_circular_prime(i)))