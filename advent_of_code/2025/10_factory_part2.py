import os
from ortools.sat.python import cp_model

def solve(line):
	line = line.strip()
	line_segments = line.split(' ')
	buttons = list(list(map(int, line_segments[i].strip('()').split(','))) for i in range(1, len(line_segments)-1))
	target_jolts = list(map(int, line_segments[-1].strip('{}').split(',')))

	target_to_buttons = {}
	for i, button in enumerate(buttons):
		for target in button:
			if target not in target_to_buttons:
				target_to_buttons[target] = []
			target_to_buttons[target].append(i)

	# print(f"buttons: {buttons}")
	# print(f"target_jolts: {target_jolts}")
	# print(f"target_to_buttons: {target_to_buttons}")
	model = cp_model.CpModel()

	button_vars = []
	for i in range(len(buttons)):
		button_var = model.NewIntVar(0, cp_model.INT32_MAX, f'button_{i}')
		button_vars.append(button_var)

	for (target, target_buttons) in target_to_buttons.items():
		model.add(sum(button_vars[i] for i in target_buttons) == target_jolts[target])

	model.minimize(sum(button_vars))
	solver = cp_model.CpSolver()
	status = solver.Solve(model)
	
	if status == cp_model.OPTIMAL:
		# print('Solution:')
		total_presses = 0
		for i in range(len(buttons)):
			num_presses = solver.Value(button_vars[i])
			total_presses += num_presses
			# print(f'Button {i} pressed {num_presses} times.')
		# print(f'Total button presses: {total_presses}')
		return total_presses
	else:
		raise Exception('No solution found.')

if __name__ == "__main__":
	ans = sum(solve(line) for line in os.sys.stdin)
	print(ans)