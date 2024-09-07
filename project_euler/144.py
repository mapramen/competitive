from math import atan, pi, tan

def normalize_angle(angle):
	while angle > 2 * pi:
		angle -= 2 * pi

	while angle < 0:
		angle += 2 * pi

	if angle > pi:
		angle -= pi

	return angle

a, b = 5, 10
x, y = 1.4, -9.6
m = (-9.6 - 10.1) / (1.4 - 0.0)

steps = 0
while x < -0.01 or x > 0.01 or y < 9.99:
	tangent_angle = normalize_angle(atan(-(b ** 2 / a ** 2) * (x / y)))
	normal_angle = normalize_angle(pi / 2 + tangent_angle)

	incident_angle = normalize_angle(atan(m))
	reflected_angle = normalize_angle(2 * normal_angle - incident_angle)

	m = tan(reflected_angle)

	new_x = (((m / b) ** 2 - (1 / a) ** 2) * x - 2 * (m / (b ** 2)) * y) / ((m / b) ** 2 + (1 / a) ** 2)
	new_y = m * (new_x - x) + y

	steps += 1
	x, y = new_x, new_y

	print(f"step = {steps} x = {x:.15f} y = {y:.15f}")