from functools import cache
import sys

sys.setrecursionlimit(200000)

@cache
def calculate(n: int, m: int, n_limit: int | None = None, m_limit: int | None = None) -> int:
	if n_limit is None:
		n_limit = n

	if m_limit is None:
		m_limit = m

	if n < 0 or m < 0:
		return 0
	
	if n == 0 and m == 0:
		return 1
	
	if n_limit <= 0 and m_limit <= 0:
		return 0
	
	next_n_limit = n_limit - 1 if m_limit == 0 else n_limit
	next_m_limit = m if m_limit == 0 else m_limit - 1

	ans = 0
	for i in range(max(n, m) + 1):
		if i * n_limit > n or i * m_limit > m:
			break
		ans += calculate(n - i * n_limit, m - i * m_limit, next_n_limit, next_m_limit)
	# print(f"Calculating for n={n}, m={m}, n_limit={n_limit}, m_limit={m_limit}, ans={ans}")
	return ans

print(calculate(60, 40))