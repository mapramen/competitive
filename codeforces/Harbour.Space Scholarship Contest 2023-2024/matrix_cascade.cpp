#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 6001

int T[N][N];
char s[N][N];

void Reset(int n) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      T[i][j] = 0;
    }
  }
}

void Update(int n, int T[], int i) {
  for (; i <= n; i += (i & -i)) {
    T[i] ^= 1;
  }
}

void Update(int n, int i, int j) {
  for (; i <= n; i += (i & -i)) {
    Update(n, T[i], j);
  }
}

int Query(int T[], int i) {
  int res = 0;
  for (; i > 0; i -= (i & -i)) {
    res ^= T[i];
  }
  return res;
}

int Query(int i, int j) {
  int res = 0;
  for (; i > 0; i -= (i & -i)) {
    res ^= Query(T[i], j);
  }
  return res;
}

int Solve() {
  int n;
  scanf("%d", &n);

  for (int x = 0; x < n; ++x) {
    scanf("%s", s[x]);
  }

  int m = 2 * n;
  Reset(m);

  int ans = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      int z = Query(x + y + 1, x - y + n);
      if (s[x][y] == '1') {
        z ^= 1;
      }

      if (z == 0) {
        continue;
      }

      ++ans;
      Update(m, x + y + 1, x - y + n);
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}