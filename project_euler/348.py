from heapq import heappop, heappush

S = set[tuple[int, int]]()
heap = list[tuple[int, int, int]]()

def check_and_push(x: int, y: int):
	if (x, y) in S:
		return
	S.add((x, y))
	heappush(heap, (x ** 2 + y ** 3, x, y))

check_and_push(2, 2)

NUMBER_OF_WAYS = 4
COUNT = 5

number_of_ways = dict[int, int]()
palindromes = set[int]()

while len(palindromes) < COUNT or (not heap and heap[0][0] <= max(palindromes)):
	n, x, y = heappop(heap)
	if str(n) == str(n)[::-1]:
		if n not in number_of_ways:
			number_of_ways[n] = 0
		number_of_ways[n] += 1
		if number_of_ways[n] == NUMBER_OF_WAYS:
			print(f"Found palindrome: {n} from ({x}, {y}) with {number_of_ways[n]} ways")
			palindromes.add(n)

		if number_of_ways[n] == NUMBER_OF_WAYS + 1:
			print(f"Removing palindrome: {n} from ({x}, {y}) with {number_of_ways[n]} ways")
			palindromes.remove(n)
	check_and_push(x + 1, y)
	check_and_push(x, y + 1)

print(sorted(palindromes))
print(sum(palindromes))