MOD = 1298074214633706835075030044377087

if __name__ == "__main__":
  for _ in range(int(input())):
    n = int(input())
    print((pow(2, n + 1, MOD) + MOD - 1) % MOD)