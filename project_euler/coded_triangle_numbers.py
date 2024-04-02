import functools

def name_score(name):
	return sum(ord(c) - 64 for c in name)

@functools.cache
def is_triangle_number(n):
	low, high, ans = 1, n, 1
	while low <= high:
		mid = (low + high) // 2
		triangle = mid * (mid + 1) // 2
		if triangle <= n:
			ans = triangle
			low = mid + 1
		else:
			high = mid - 1
	return ans == n

def is_coded_triangle_number(name):
	return is_triangle_number(name_score(name))

ans = sum(1 for name in input().split(',') if is_coded_triangle_number(name.strip('"')))
print(ans)