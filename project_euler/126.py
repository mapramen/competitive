from heapq import heappop, heappush

def calculate_cubes_in_layer(n, a, b, c):
	return 2 * (a * b + b * c + c * a) + 4 * (n - 1) * (a + b + c) + 4 * (n - 1) * (n - 2)

def check_and_push(S, Q, n, a, b, c):
	if a > b or b > c or a > c:
		return
	if (n, a, b, c) in S:
		return
	S.add((n, a, b, c))
	heappush(Q, (calculate_cubes_in_layer(n, a, b, c), n, a, b, c))

S = set()
Q = []
check_and_push(S, Q, 1, 1, 1, 1)

while Q:
	cube_count = Q[0][0]

	cnt = 0
	while Q and Q[0][0] == cube_count:
		(_, n, a, b, c) = heappop(Q)
		cnt += 1
		check_and_push(S, Q, n+1, a, b, c)
		check_and_push(S, Q, n, a+1, b, c)
		check_and_push(S, Q, n, a, b+1, c)
		check_and_push(S, Q, n, a, b, c+1)

	print(cube_count, cnt)
	if cnt == 1000:
		break