#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 51

int degree[N];

bool Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  ll m = 0;
  for (int x : a) {
    m += x;
  }

  if (m % n != 0) {
    return false;
  }

  m /= n;

  for (int i = 0; i < N; ++i) {
    degree[i] = 0;
  }

  for (int x : a) {
    if (x == m) {
      continue;
    }

    int i = 0, j = -1;
    for (; i < N; ++i) {
      ll z = (1LL << i) + m - x;
      if (z <= 0) {
        continue;
      }

      if ((z & (z - 1)) != 0) {
        continue;
      }

      j = __builtin_ctzll(z);
      if (j >= N) {
        j = -1;
        continue;
      }

      break;
    }

    if (j == -1) {
      return false;
    }

    ++degree[j];
    --degree[i];
  }

  for (int i = 0; i < N; ++i) {
    if (degree[i] != 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}