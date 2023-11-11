#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  string s;
  if (!getline(cin, s)) {
    exit(0);
  }

  vector<pair<char, int>> a;
  for (int n = s.size(), i = 0; i < n;) {
    char c = s[i];

    int cnt = 0;
    while (i < n && s[i] == c) {
      ++i;
      ++cnt;
    }

    a.push_back({c, cnt});
  }
  reverse(a.begin(), a.end());

  string ans;
  while (!a.empty()) {
    if (a.back().second > 1) {
      auto [c, cnt] = a.back();
      a.pop_back();

      int d = min(cnt, 9);
      ans.push_back('0' + d);
      ans.push_back(c);
      cnt -= d;

      if (cnt > 0) {
        a.push_back({c, cnt});
      }
      continue;
    }

    ans.push_back('1');
    while (!a.empty() && a.back().second == 1) {
      auto [c, _] = a.back();
      a.pop_back();

      ans.push_back(c);
      if (c == '1') {
        ans.push_back('1');
      }
    }
    ans.push_back('1');
  }

  return ans;
}

int main() {
  while (true) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}