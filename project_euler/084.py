from random import randint
from time import sleep

square_number_to_square_name = {
	0: 'GO',
	1: 'A1',
	2: 'CC1',
	3: 'A2',
	4: 'T1',
	5: 'R1',
	6: 'B1',
	7: 'CH1',
	8: 'B2',
	9: 'B3',
	10: 'JAIL',
	11: 'C1',
	12: 'U1',
	13: 'C2',
	14: 'C3',
	15: 'R2',
	16: 'D1',
	17: 'CC2',
	18: 'D2',
	19: 'D3',
	20: 'FP',
	21: 'E1',
	22: 'CH2',
	23: 'E2',
	24: 'E3',
	25: 'R3',
	26: 'F1',
	27: 'F2',
	28: 'U2',
	29: 'F3',
	30: 'G2J',
	31: 'G1',
	32: 'G2',
	33: 'CC3',
	34: 'G3',
	35: 'R4',
	36: 'CH3',
	37: 'H1',
	38: 'T2',
	39: 'H2',
}

def get_square_number(square_name):
	for k in square_number_to_square_name:
		if square_number_to_square_name[k] == square_name:
			return k
	return -1

def get_next_square_number_with_name(square_number, square_name):
	while not square_number_to_square_name[square_number].startswith(square_name):
		square_number = (square_number + 1) % 40
	return square_number

def get_next_square_number(x, y):
	square_number = (x + y) % 40
	square_name = square_number_to_square_name[square_number]
	
	if square_name == 'G2J':
		return get_square_number('JAIL')
	
	if square_name.startswith('CC'):
		random_int = randint(1, 16)
		if random_int == 1:
			return get_square_number('GO')
		if random_int == 2:
			return get_square_number('JAIL')
		
	if square_name.startswith('CH'):
		random_int = randint(1, 16)
		if random_int == 1:
			return get_square_number('GO')
		if random_int == 2:
			return get_square_number('JAIL')
		if random_int == 3:
			return get_square_number('C1')
		if random_int == 4:
			return get_square_number('E3')
		if random_int == 5:
			return get_square_number('H2')
		if random_int == 6:
			return get_square_number('R1')
		if random_int == 7:
			return get_next_square_number_with_name(square_number, 'R')
		if random_int == 8:
			return get_next_square_number_with_name(square_number, 'R')
		if random_int == 9:
			return get_next_square_number_with_name(square_number, 'U')
		if random_int == 10:
			return get_next_square_number(square_number, 40 - 3)
		
	return square_number

NUMBER_OF_SIDES_IN_DIE = 4
DOUBLE_COUNT_THRESHOLD = 3

p = [0] * 40

iteration_number = 0
square_number = 0
double_cnt = 0
while True:
	d1 = randint(1, NUMBER_OF_SIDES_IN_DIE)
	d2 = randint(1, NUMBER_OF_SIDES_IN_DIE)

	square_number = get_next_square_number(square_number, d1 + d2)
	double_cnt = 1 + double_cnt if d1 == d2 else 0
	if double_cnt == DOUBLE_COUNT_THRESHOLD:
		square_number = get_square_number('JAIL')
		double_cnt = 0

	p[square_number] += 1
	iteration_number += 1

	if iteration_number % 1000000 != 0:
		continue

	print('iteration_number: ', iteration_number)
	a = sorted(range(40), key= lambda x: p[x])
	for i in a:
		print(p[i] / iteration_number, square_number_to_square_name[i])

	print(''.join(f"{i:02}" for i in a[-3:][::-1]))