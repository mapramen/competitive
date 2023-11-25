#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string ReadString() {
  string s;
  getline(cin, s);
  return s;
}

ll Solve(string& s) {
  if (s.empty() || s.back() == ']') {
    return 1;
  }

  s.pop_back();
  ll left_ans = Solve(s);
  ll right_ans = Solve(s);
  s.pop_back();

  return 2 * left_ans * right_ans / __gcd(left_ans, right_ans);
}

ll Solve() {
  string s = ReadString();
  reverse(s.begin(), s.end());
  return Solve(s);
}

int main() {
  int t = stoi(ReadString());
  for (int k = 1; k <= t; ++k) {
    printf("%d %lld\n", k, Solve());
  }
  return 0;
}