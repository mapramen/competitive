#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define REPETITIONS 5

vector<int> ReadNumbers() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  vector<int> numbers;

  string t;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isdigit(c)) {
      t.push_back(c);
    }

    if (!s.empty() && isdigit(s.back()) || t.empty()) {
      continue;
    }

    int number = stoi(t);
    t.clear();

    numbers.push_back(number);
  }

  return numbers;
}

string GetUnfolded(string s) {
  for (int n = s.size(), k = 1; k < REPETITIONS; ++k) {
    s.push_back('?');
    for (int i = 0; i < n; ++i) {
      s.push_back(s[i]);
    }
  }
  return s;
}

vector<int> GetUnfolded(vector<int> a) {
  for (int n = a.size(), k = 1; k < REPETITIONS; ++k) {
    for (int i = 0; i < n; ++i) {
      a.push_back(a[i]);
    }
  }
  return a;
}

ll Calculate(vector<int> a, string s) {
  a = GetUnfolded(a);
  s = GetUnfolded(s);

  int n = a.size(), m = s.size();
  vector<int> cnt(m + 1);
  for (int j = 1; j <= m; ++j) {
    cnt[j] = cnt[j - 1] + (s[j - 1] == '.');
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));

  dp[0][0] = 1;
  for (int j = 1; j <= m && s[j - 1] != '#'; ++j) {
    dp[0][j] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[j - 1] == '.') {
        dp[i][j] = dp[i][j - 1];
        continue;
      }

      if (s[j - 1] == '?') {
        dp[i][j] = dp[i][j - 1];
      }

      int x = a[i - 1], k = j - x;
      if (k < 0 || cnt[j] - cnt[k] != 0) {
        continue;
      }

      if (k == 0) {
        dp[i][j] += dp[i - 1][k];
        continue;
      }

      if (s[k - 1] != '#') {
        dp[i][j] += dp[i - 1][k - 1];
      }
    }
  }

  return dp[n][m];
}

int main() {
  ll ans = 0;

  while (true) {
    string s;
    if (!(cin >> s)) {
      break;
    }

    vector<int> a = ReadNumbers();
    ans += Calculate(a, s);
  }

  cout << ans << '\n';

  return 0;
}