#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 17

char s[N];
int a[N], b[N];

vector<pii> Calculate(int n, int m, int mask) {
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }

  vector<pii> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((mask & (1 << j)) != 0) {
        ans.push_back({i, j});
      }
    }

    a[i + 1] ^= mask;

    mask = mask ^ (mask >> 1) ^ ((mask << 1) & ((1 << m) - 1));
    mask ^= a[i];
  }
  return mask == 0 ? ans : vector<pii>{{-1, -1}};
}

vector<pii> Solve() {
  int n, m;
  scanf("%d%d", &m, &n);

  if (n == 0 && m == 0) {
    exit(0);
  }

  for (int i = 0; i < n; ++i) {
    scanf("%s", s);

    int on_mask = 0;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '0') {
        on_mask |= (1 << j);
      }
    }
    b[i] = on_mask;
  }

  vector<pii> ans = {{-1, -1}};
  for (int mask = 0; mask < (1 << m) && !ans.empty() && ans.back().first == -1; ++mask) {
    ans = Calculate(n, m, mask);
  }
  return ans;
}

int main() {
  while (true) {
    vector<pii> ans = Solve();
    if (!ans.empty() && ans.back().first == -1) {
      printf("-1\n");
      continue;
    }

    printf("%lu\n", ans.size());
    for (auto [x, y] : ans) {
      printf("%d %d\n", y + 1, x + 1);
    }
  }
  return 0;
}