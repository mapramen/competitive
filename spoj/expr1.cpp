#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 20

map<int, int> unsigned_dp[N][N], signed_dp[N][N];

void Update(map<int, int>& dp, int k, int v) {
  auto it = dp.find(k);
  if (it == dp.end()) {
    dp[k] = v;
  } else {
    it->second = min(it->second, v);
  }
}

void UpdateSigned(int i, int j, int sign, int cost) {
  for (auto [k, v] : unsigned_dp[i][j]) {
    Update(signed_dp[i][j], sign * k, v + cost);
  }
}

string Solve() {
  int n, target;
  scanf("%d%d", &n, &target);

  string s;
  cin >> s;

  n /= 2;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      unsigned_dp[i][j].clear();
      signed_dp[i][j].clear();
    }
  }

  for (int i = 0; i < n; ++i) {
    int val = s[2 * i + 1] - '0';
    int sign = s[2 * i] == '+' ? 1 : -1;

    unsigned_dp[i][i][val] = 0;
    UpdateSigned(i, i, sign, 0);
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 0, j = len - 1; j < n; ++i, ++j) {
      for (int k = i; k < j; ++k) {
        for (auto [k1, v1] : signed_dp[k + 1][j]) {
          for (auto [k2, v2] : unsigned_dp[i][k]) {
            Update(unsigned_dp[i][j], k1 + k2, v1 + v2);
          }

          for (auto [k2, v2] : signed_dp[i][k]) {
            Update(signed_dp[i][j], k1 + k2, v1 + v2);
          }
        }
      }
      UpdateSigned(i, j, s[2 * i] == '+' ? 1 : -1, 1);
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = i; j < n; ++j) {
  //     printf("i = %d, j = %d\n", i, j);
  //     for (auto [k, v] : unsigned_dp[i][j]) {
  //       printf("unsigned_dp[%d] = %d\n", k, v);
  //     }
  //     for (auto [k, v] : signed_dp[i][j]) {
  //       printf("signed_dp[%d] = %d\n", k, v);
  //     }
  //     printf("\n");
  //   }
  // }

  auto it = signed_dp[0][n - 1].find(target);
  return it != signed_dp[0][n - 1].end() ? to_string(it->second) : "NO";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}