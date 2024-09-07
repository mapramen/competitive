import functools
from math import floor

@functools.cache
def solve(turn_count, red_count, blue_count, red_taken_count, blue_taken_count):
	if turn_count == 0:
		return 1 if blue_taken_count > red_taken_count else 0
	
	probability_if_red_taken = red_count / (red_count + blue_count) * solve(turn_count - 1, red_count + 1, blue_count, red_taken_count + 1, blue_taken_count)
	probability_if_blue_taken = blue_count / (red_count + blue_count) * solve(turn_count - 1, red_count + 1, blue_count, red_taken_count, blue_taken_count + 1)
	return probability_if_red_taken + probability_if_blue_taken

def disc_game_prize_fund(turn_count):
	return floor(1 / solve(turn_count, 1, 1, 0, 0))

print(disc_game_prize_fund(15))