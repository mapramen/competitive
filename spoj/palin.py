def get_palindrome_candidates(n, z):
  n = n.rjust(z, '0')
  return [n + n[::-1], n + n[-2::-1]]

def next_palindrome(n):
  if n[-1] == '9':
    z = len(n)
    n = str(int(n) + 1)
    n = n.rjust(z, '0')

  a = n[0 : (len(n) + 1)//2]
  z = len(a)
  palindrome_candidates = get_palindrome_candidates(a, z) + get_palindrome_candidates(str(int(a) + 1), z)
  
  ans = n + n
  for palindrome_candidate in palindrome_candidates:
    if len(palindrome_candidate) > len(n) or (len(palindrome_candidate) == len(n) and palindrome_candidate > n):
      if len(palindrome_candidate) < len(ans) or (len(palindrome_candidate) == len(ans) and palindrome_candidate < ans):
        ans = palindrome_candidate

  return ans

if __name__ == "__main__":
  t = int(input())
  for _ in range(0, t):
    n = input().strip()
    print(next_palindrome(n))