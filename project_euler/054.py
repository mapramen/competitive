import sys

def get_card_value(card):
	c = card[0]

	if c == 'T':
		return 10
	
	if c == 'J':
		return 11
	
	if c == 'Q':
		return 12
	
	if c == 'K':
		return 13
	
	if c == 'A':
		return 14
	
	return int(c)

def get_hand_characteristics(hand):
	suits = set(card[1] for card in hand)
	values = sorted(get_card_value(card) for card in hand)[::-1]

	def is_straight(a):
		return len(set(a[i] + i for i in range(5))) == 1

	# Royal flush
	if len(suits) == 1 and values[0] == 14 and is_straight(values):
		return (10, values)
	
	# Straight flush
	if len(suits) == 1 and is_straight(values):
		return (9, values)
	
	# Four of a kind
	if values[0] == values[3] or values[1] == values[4]:
		return (8, values[2], values)
	
	# Full house
	if values[0] == values[2] and values[3] == values[4]:
		return (7, values[2], values[3])
	
	if values[2] == values[4] and values[0] == values[1]:
		return (7, values[2], values[0])
	
	# Flush
	if len(suits) == 1:
		return (6, values)
	
	# Straight
	if is_straight(values):
		return (5, values)
	
	# Three of a kind
	if values[0] == values[2] or values[1] == values[3] or values[2] == values[4]:
		return (4, values[2], values)
	
	# Two pairs
	if values[0] == values[1] and values[2] == values[3]:
		return (3, values[0], values[2], values)
	
	if values[0] == values[1] and values[3] == values[4]:
		return (3, values[0], values[3], values)
	
	if values[1] == values[2] and values[3] == values[4]:
		return (3, values[1], values[3], values)
	
	# One pair
	if values[0] == values[1]:
		return (2, values[0], values)
	
	if values[1] == values[2]:
		return (2, values[1], values)
	
	if values[2] == values[3]:
		return (2, values[2], values)
	
	if values[3] == values[4]:
		return (2, values[3], values)
	
	# High card
	return (1, values)

def winner(hand1, hand2):
	return get_hand_characteristics(hand1) > get_hand_characteristics(hand2)

def is_winner_player1(line):
	tokens = line.split()
	return winner(tokens[:5], tokens[5:]) == 1

ans = sum(1 for line in sys.stdin.readlines() if is_winner_player1(line))
print(ans)