from math import sqrt

def calculate(x, y, z):
  a = y + 2 * z
  b = -2 * x * z
  c = -y * z * z

  t = (-b + sqrt(b * b - 4 * a * c)) / (2 * a)
  if t < 0 or t > x or not t.is_integer():
    return -1
  
  return int(t)

if __name__ == "__main__":
  t = int(raw_input())
  for _ in range(0, t):
    x, y, z = map(int, raw_input().split(" "))
    t = calculate(x, y, z)
    if t == -1:
      print("Not this time.")
    else:
      print(t)