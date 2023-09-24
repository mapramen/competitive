#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 51

int degree[N], mor[N], les[N];

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
    degree[i] = 0, mor[i] = 0, les[i] = 0;
  }

  for (int x : a) {
    if (x == m) {
      continue;
    }

    int y = x - m;
    if (y > 0 && (y & (y - 1)) == 0) {
      ++mor[__builtin_ctz(y)];
      continue;
    }

    y = m - x;
    if (y > 0 && (y & (y - 1)) == 0) {
      ++les[__builtin_ctz(y)];
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

  for (int i = N - 1; i > -1; --i) {
    degree[i] += les[i];
    degree[i] -= mor[i];

    les[i] = 0, mor[i] = 0;

    if (degree[i] > 0 && i != 0) {
      int z = min(mor[i - 1], degree[i]);
      mor[i - 1] -= z;
      degree[i] -= z;
      degree[i - 1] += z;
    }

    if (degree[i] < 0 && i != 0) {
      int z = min(les[i - 1], -degree[i]);
      les[i - 1] -= z;
      degree[i] += z;
      degree[i - 1] -= z;
    }

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