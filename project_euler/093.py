from itertools import combinations, permutations, product

cache = {}

def get_arithmetic_expressions(a, i, j):
	cache_key = tuple(a[i:j+1])
	if cache_key in cache:
		return cache[cache_key]
	
	ans = set()
	cache[cache_key] = ans

	if i == j:
		ans.add(float(a[i]))
		return ans
	
	for k in range(i, j):
		left = get_arithmetic_expressions(a, i, k)
		right = get_arithmetic_expressions(a, k + 1, j)
		for l, r in product(left, right):
			ans.add(l + r)
			ans.add(l - r)
			ans.add(l * r)
			if r != 0:
				ans.add(l / r)

	return ans

def get_consecutive_length(max_length, combination):
	expression_values = set()

	for permutation in permutations(combination):
		for expression_value in get_arithmetic_expressions(permutation, 0, len(combination) - 1):
			if expression_value > 0 and expression_value.is_integer():
				expression_values.add(expression_value)

	n = 1
	while n in expression_values:
		n += 1
	n -= 1

	if n <= max_length:
		return n

	print(n, combination)
	return n
	
max_length = 0
for combination in combinations(range(1, 10), 5):
	max_length = max(max_length, get_consecutive_length(max_length, combination))
