#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii Solve(string& s, int& cuts, int depth) {
  if (s.empty()) {
    return {depth, cuts};
  }

  char c = s.back();
  s.pop_back();

  if (c == '0') {
    return {depth, cuts};
  }

  ++cuts;
  auto [left_depth, left_cuts] = Solve(s, cuts, depth + 1);
  auto [right_depth, right_cuts] = Solve(s, cuts, depth + 1);

  if (left_depth >= right_depth) {
    return {left_depth, left_cuts};
  }

  return {right_depth, right_cuts};
}

int Solve() {
  int n;
  string s;

  cin >> n >> s;

  reverse(s.begin(), s.end());

  int cuts = 0;
  auto [_, ans] = Solve(s, cuts, 0);
  return ans;
}

int main() {
  int t = 10;
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}