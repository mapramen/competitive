from collections import deque
import functools
import sys

ATTEMPT_LENGTH = 3

def search_bfs(attempts):
	n = len(attempts)
	Q = deque()
	Q.append(('', [0] * n))

	while Q:
		s, mask = Q.popleft()
		if all(j == ATTEMPT_LENGTH for j in mask):
			return s

		candidates = set(attempts[i][j] for i, j in enumerate(mask) if j != ATTEMPT_LENGTH)
		
		for candidate in candidates:
			new_s = s + candidate
			new_mask = [j + 1 if j != ATTEMPT_LENGTH and attempts[i][j] == candidate else j for i, j in enumerate(mask)]
			Q.append((new_s, new_mask))

	return ''.join(attempts)

def search_dfs(attempts):
	n = len(attempts)

	@functools.cache
	def dfs(allowed_length, mask):
		if all(j == ATTEMPT_LENGTH for j in mask):
			return ''

		ans = ''.join(attempts[i][j:] for i, j in enumerate(mask))
		candidates = set(attempts[i][j] for i, j in enumerate(mask) if j != ATTEMPT_LENGTH)

		if len(set(ans)) >= allowed_length:
			return ans
		
		allowed_length = len(ans)
		for candidate in candidates:
			new_mask = tuple(j + 1 if j != ATTEMPT_LENGTH and attempts[i][j] == candidate else j for i, j in enumerate(mask))
			result = dfs(allowed_length, new_mask)
			if 1 + len(result) < len(ans):
				ans = candidate + result
				allowed_length = len(ans)
		return ans

	return dfs(sum(len(attempt) for attempt in attempts), tuple([0] * n))

attempts = sorted(line.strip() for line in sys.stdin.readlines())
# print(search_bfs(attempts))
print(search_dfs(attempts))