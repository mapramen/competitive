def get_kth_permutation(n, k):
	from math import factorial

	k -= 1
	perm = []
	numbers = list(range(0, n))

	for i in range(n):
		fact = factorial(n - 1 - i)
		index = k // fact
		k = k % fact
		perm.append(numbers[index])
		numbers.pop(index)

	return perm

print(''.join(str(i) for i in get_kth_permutation(10, 1000000)))