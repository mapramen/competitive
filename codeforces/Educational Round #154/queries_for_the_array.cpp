#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

tuple<bool, bool, bool> Solve(string& s, int d) {
  bool is_increasing = d < 2;
  bool is_not_increasing = false;

  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (c == '-') {
      break;
    }

    if (c == '0') {
      if (is_increasing) {
        return {false, false, false};
      }
      is_not_increasing = true;
      continue;
    }

    if (c == '1') {
      if (is_not_increasing) {
        return {false, false, false};
      }
      is_increasing = true;
      continue;
    }

    auto [valid, is_increasing_, is_not_increasing_] = Solve(s, d + 1);
    if (!valid || is_not_increasing && is_increasing_) {
      return {false, false, false};
    }

    is_increasing = is_increasing || is_increasing_;
  }

  return {true, is_increasing, is_not_increasing};
}

bool Solve() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  auto [valid, _, __] = Solve(s, 0);
  return valid;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}