def isPalindrome(n):
  assert(n >= 0)
  return str(n) == str(n)[::-1]

largestPalindrome = -1

for x in range(999, 99, -1):
  if x % 11 == 0:
    ry, dy = 999, -1
  else:
    ry, dy = 990, -11

  for y in range(ry, 99, dy):
    if x * y <= largestPalindrome:
      break

    if isPalindrome(x * y):
      largestPalindrome = x * y
      break

print(largestPalindrome)