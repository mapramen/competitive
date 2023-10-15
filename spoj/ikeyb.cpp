#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pair<char, string>> Solve() {
  int k, l;
  scanf("%d%d", &k, &l);

  string keys, letters;
  cin >> keys;
  cin >> letters;

  vector<int> freq(l + 1);
  for (int i = 1; i <= l; ++i) {
    scanf("%d", &freq[i]);
  }

  vector<vector<pii>> dp(k + 1, vector<pii>(l + 1, {1E9, -1}));

  dp[0][0] = {0, 0};
  for (int i = 1; i <= l; ++i) {
    for (int j = i, cost = 0, sum = 0; j > 0; --j) {
      sum += freq[j];
      cost += sum;

      for (int x = 1; x <= k; ++x) {
        dp[x][i] = min(dp[x][i], {dp[x - 1][j - 1].first + cost, j - 1});
      }
    }
  }

  vector<pair<char, string>> ans;
  for (int x = k, i = l; x > 0; --x) {
    auto [_, j] = dp[x][i];

    string s;
    for (int z = j; z < i; ++z) {
      s.push_back(letters[z]);
    }

    ans.push_back({keys[x - 1], s});
    i = j;
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Keypad #%d:\n", k);
    for (auto [c, s] : Solve()) {
      printf("%c: %s\n", c, s.c_str());
    }
  }
  return 0;
}