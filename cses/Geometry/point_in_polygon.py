def point_in_polygon(polygon, point):
	# Ray-casting algorithm to determine if point is inside, outside or on the boundary of the polygon
	x, y = point
	n = len(polygon)
	inside = False
	for i in range(n):
		x1, y1 = polygon[i]
		x2, y2 = polygon[(i + 1) % n]

		# Check if point is on the boundary (edge) of the polygon
		if (y2 - y1) * (x - x1) == (x2 - x1) * (y - y1) and min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
			return "BOUNDARY"

		# Check if the ray intersects with the edge
		if ((y1 > y) != (y2 > y)) and (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1):
			inside = not inside
	return "INSIDE" if inside else "OUTSIDE"

if __name__ == "__main__":
	n, m = map(int, input().split())
	
	polygon = [tuple(map(int, input().split())) for _ in range(n)]

	for _ in range(m):
		point = tuple(map(int, input().split()))
		print(point_in_polygon(polygon, point))