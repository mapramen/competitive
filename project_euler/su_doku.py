from copy import deepcopy
import sys

def box_number(x, y):
	return (x // 3) * 3 + y // 3

def get_next_position(i, j):
	if j == 8:
		return i + 1, 0
	return i, j + 1

def solve(row_set, col_set, box_set, a, i, j):
	if i == 9:
		return deepcopy(a)

	if a[i][j] != 0:
		return solve(row_set, col_set, box_set, a, *get_next_position(i, j))
	
	for num in range(1, 10):
		if num in row_set[i] or num in col_set[j] or num in box_set[box_number(i, j)]:
			continue

		a[i][j] = num
		row_set[i].add(num)
		col_set[j].add(num)
		box_set[box_number(i, j)].add(num)

		solution = solve(row_set, col_set, box_set, a, *get_next_position(i, j))

		a[i][j] = 0
		row_set[i].remove(num)
		col_set[j].remove(num)
		box_set[box_number(i, j)].remove(num)

		if solution:
			return solution
		
	return None

def solve_sudoku(a):
	row_set = [set() for _ in range(9)]
	col_set = [set() for _ in range(9)]
	box_set = [set() for _ in range(9)]

	for i in range(9):
		for j in range(9):
			if a[i][j] != 0:
				row_set[i].add(a[i][j])
				col_set[j].add(a[i][j])
				box_set[box_number(i, j)].add(a[i][j])

	return solve(row_set, col_set, box_set, a, 0, 0)

lines = sys.stdin.readlines()

ans = 0
for i in range(0, len(lines), 10):
	a = []
	for j in range(1, 10):
		a.append(list(map(int, lines[i + j].strip())))
	solution = solve_sudoku(a)
	if not solution:
		print("No solution")
		break
	print(*solution, sep='\n')
	print()
	ans += 100 * solution[0][0] + 10 * solution[0][1] + solution[0][2]
	
print(ans)