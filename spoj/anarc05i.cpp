#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  string s;
  cin >> s;

  if (s.front() == 'Q') {
    exit(0);
  }

  set<pii> S;

  int x = 0, y = 0;
  S.insert({x, y});

  for (char c : s) {
    if (c == 'Q') {
      break;
    }

    if (c == 'U') {
      ++y;
    }

    if (c == 'D') {
      --y;
    }

    if (c == 'L') {
      --x;
    }

    if (c == 'R') {
      ++x;
    }

    S.insert({x, y});
  }

  return s.size() - S.size();
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}