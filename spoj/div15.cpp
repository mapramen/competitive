#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 10
#define THREE 3

string GetMaxMod3(vector<int> cnt, int mod) {
  vector<int> a;
  for (int k = B - 1; k > -1; --k) {
    while (cnt[k] > 0) {
      a.push_back(k);
      --cnt[k];
    }
  }

  int n = a.size();
  vector<vector<pii>> dp(n + 1, vector<pii>(THREE, {-1, -1}));

  dp[0][0] = {0, 0};
  for (int i = 0; i < n; ++i) {
    for (int r = 0; r < THREE; ++r) {
      auto [len, _] = dp[i][r];
      dp[i + 1][r] = {len, 1};
    }

    for (int r = 0; r < THREE; ++r) {
      auto [len, _] = dp[i][r];
      if (len == -1) {
        continue;
      }

      int new_r = (r + a[i]) % THREE;
      dp[i + 1][new_r] = max(dp[i + 1][new_r], {len + 1, 0});
    }
  }

  string s;
  for (int i = n; i > 0; --i) {
    auto [len, z] = dp[i][mod];
    if (len == -1) {
      break;
    }

    if (z == 1) {
      continue;
    }

    s.push_back(a[i - 1] + '0');
    mod = (mod - a[i - 1] + THREE) % THREE;
    mod = (mod + THREE) % THREE;
  }
  reverse(s.begin(), s.end());

  return s;
}

string NormalizeNumber(string s) {
  reverse(s.begin(), s.end());
  while (s.size() > 1 && s.back() == '0') {
    s.pop_back();
  }
  reverse(s.begin(), s.end());
  return s;
}

string GetMaxNumber(string a, string b) {
  a = NormalizeNumber(a);
  b = NormalizeNumber(b);

  if (a.size() > b.size()) {
    return a;
  }

  if (a.size() < b.size()) {
    return b;
  }

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) {
      return a;
    }

    if (a[i] < b[i]) {
      return b;
    }
  }

  return a;
}

string Solve() {
  string s;
  cin >> s;

  vector<int> cnt(B);
  for (char c : s) {
    ++cnt[c - '0'];
  }

  string ans1;
  if (cnt[0] != 0) {
    ans1 = GetMaxMod3(cnt, 0);
  }

  string ans2;
  if (cnt[5] != 0) {
    --cnt[5];
    ans2 = GetMaxMod3(cnt, 1);
    ++cnt[5];

    if (!ans2.empty()) {
      ans2.push_back('5');
    }
  }

  string ans = GetMaxNumber(ans1, ans2);
  if (ans.empty()) {
    ans = "impossible";
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}