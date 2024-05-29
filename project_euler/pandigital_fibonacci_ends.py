from math import log10, sqrt

MOD = 10**9

def is_pan_digital(s):
	return len(s) == 9 and set(s) == set('123456789')

log_phi = log10((1 + sqrt(5)) / 2)
log_sqrt_5 = log10(5) / 2

a, b = 0, 1

n = 0
while True:
	n += 1
	a, b = (a + b) % MOD, a

	if not is_pan_digital(str(a)):
		continue

	log_fn = n * log_phi - log_sqrt_5
	first_9_digits = int(10 ** (log_fn - int(log_fn) + 8))

	if is_pan_digital(str(first_9_digits)):
		print(n, a, first_9_digits)