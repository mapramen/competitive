from heapq import heappop, heappush

def check_and_push(S, Q, x, y):
	if (x, y) in S:
		return
	S.add((x, y))
	heappush(Q, (x, y))

def generate_next_candidates(x, y):
	yield (- 9 * x - 4 * y - 14, - 20 * x - 9 * y - 28)
	yield (- 9 * x + 4 * y - 14, + 20 * x - 9 * y + 28)

S = set()
Q = []

check_and_push(S, Q, 2, -7)
check_and_push(S, Q, 0, 1)
check_and_push(S, Q, -4, 5)
check_and_push(S, Q, -3, 2)
check_and_push(S, Q, -3, -2)

golden_nuggets = set()
cnt, ans = 0, 0
while Q:
	(x, y) = heappop(Q)

	if x > 0 and x not in golden_nuggets:
		golden_nuggets.add(x)
		cnt += 1
		ans += x
		print(f"cnt = {cnt}, x = {x}, ans = {ans}")

	if cnt == 30:
		break

	for (nx, ny) in generate_next_candidates(x, y):
		check_and_push(S, Q, nx, ny)