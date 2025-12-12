import os
from ortools.sat.python import cp_model

def extract_present(lines):
	present = []

	lines.pop(0)
	while lines[0]:
		present.append(lines.pop(0))
	lines.pop(0)

	return present

def extract_presents(lines):
	presents = []

	while lines:
		x_index = lines[0].find('x')
		if x_index != -1:
			break

		presents.append(extract_present(lines))

	return presents

def extract_region(line):
	tokens = list(token.strip() for token in line.split())
	
	m, n = map(int, tokens[0].strip(':').split('x'))
	cnts = list(map(int, tokens[1:]))
	return (n, m, cnts)

def get_rotated(present):
	# Rotate 90 degrees clockwise
	return [''.join(present[len(present)-1-j][i] for j in range(len(present))) for i in range(len(present[0]))]

def get_flipped(present):
	# Flip horizontally
	return [row[::-1] for row in present]

def get_orientations(present):
	orientations = set()
	orientations.add(tuple(present))

	Q = [present]
	while Q:
		curr = Q.pop()
		rotated = get_rotated(curr)
		flipped = get_flipped(curr)

		for new_present in [rotated, flipped]:
			present_tuple = tuple(new_present)
			if present_tuple not in orientations:
				orientations.add(present_tuple)
				Q.append(new_present)

	return [list(p) for p in orientations]

def is_definitely_possible(presents_with_orientations, n, m, cnts):
	needed_block_cnt = sum(cnts)
	available_block_cnt = (n // 3) * (m // 3)

	if needed_block_cnt <= available_block_cnt:
		return True
	
	return False

def is_definitely_not_possible(presents_with_orientations, n, m, cnts):
	available_cell_cnt = n * m
	needed_cell_cnt = 0
	for p_index, present_with_orientations in enumerate(presents_with_orientations):
		if cnts[p_index] == 0:
			continue
		present = present_with_orientations[0]
		present_cells = sum(row.count('#') for row in present)
		needed_cell_cnt += present_cells * cnts[p_index]

	if needed_cell_cnt > available_cell_cnt:
		return True
	
	return False

def is_possible(presents_with_orientations, n, m, cnts):
	if is_definitely_possible(presents_with_orientations, n, m, cnts):
		print('definitely possible')
		return True
	
	if is_definitely_not_possible(presents_with_orientations, n, m, cnts):
		print('definitely not possible')
		return False
	
	print('solving with CP-SAT...')
	model = cp_model.CpModel()

	present_cnt_restrictions = [[] for _ in range(len(cnts))]
	present_restrictions = {}
	cell_restrictions = {}
	vars = {}

	for p_index, present_with_orientations in enumerate(presents_with_orientations):
		if cnts[p_index] == 0:
			continue

		for orientation_index, present in enumerate(present_with_orientations):
			a, b = len(present), len(present[0])

			for xr in range(n - a + 1):
				for yr in range(m - b + 1):
					var = model.NewBoolVar(f'{p_index}_{orientation_index}_{xr}_{yr}')
					vars[(p_index, orientation_index, xr, yr)] = var

					present_cnt_restrictions[p_index].append(var)

					if (p_index, xr, yr) not in present_restrictions:
						present_restrictions[(p_index, xr, yr)] = []
					present_restrictions[(p_index, xr, yr)].append(var)
					
					for xp in range(a):
						for yp in range(b):
							if present[xp][yp] != '#':
								continue

							if (xr + xp, yr + yp) not in cell_restrictions:
								cell_restrictions[(xr + xp, yr + yp)] = []
							cell_restrictions[(xr + xp, yr + yp)].append((p_index, orientation_index, xr, yr))

	for p_index, present_cnt_restriction in enumerate(present_cnt_restrictions):
		cnt = cnts[p_index]
		if cnt == 0:
			continue
		model.Add(sum(present_cnt_restriction) == cnt)

	for present_restriction in present_restrictions.values():
		model.AddAtMostOne(present_restriction)

	cell_restrictions_set = set(tuple(cell_restriction) for cell_restriction in cell_restrictions.values())

	for cell_restriction in cell_restrictions_set:
		model.AddAtMostOne(vars[key] for key in cell_restriction)

	solver = cp_model.CpSolver()
	solver.parameters.num_search_workers = 14
	status = solver.Solve(model)

	if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
		# print the solution
		# print('Solution found:')
		# for key, var in vars.items():
		# 	if solver.Value(var) == 1:
		# 		p_index, orientation_index, xr, yr = key
		# 		print(f'Present {p_index} placed at ({xr}, {yr}) with orientation {orientation_index}')
		# 		print('Orientation:')
		# 		for row in presents_with_orientations[p_index][orientation_index]:
		# 			print(row)
		# 		print()
		return True
	else:
		return False

if __name__ == "__main__":
	lines = list(line.strip() for line in os.sys.stdin)
	presents = extract_presents(lines)

	presents_with_orientations = list(get_orientations(p) for p in presents)

	ans = 0
	for line in lines:
		n, m, cnts = extract_region(line)
		if is_possible(presents_with_orientations, n, m, cnts):
			ans += 1
	print(ans)