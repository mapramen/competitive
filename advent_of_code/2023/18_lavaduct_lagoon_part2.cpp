#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tinput tuple<char, int>

char DirectionInt2Char(int direction) {
  if (direction == 0) {
    return 'R';
  }

  if (direction == 1) {
    return 'D';
  }

  if (direction == 2) {
    return 'L';
  }

  if (direction == 3) {
    return 'U';
  }

  assert(false);
}

vector<tinput> ReadInput() {
  vector<tinput> a;
  while (true) {
    string s;
    if (!getline(cin, s) || s.empty()) {
      break;
    }

    int n = s.size();

    char direction = DirectionInt2Char(s[n - 2] - '0');
    int steps = stoi(string(s, n - 7, 5), 0, 16);

    a.push_back({direction, steps});
  }
  return a;
}

ll Solve(vector<pii> p) {
  ll area = 0, boundary_points = 0;
  for (int n = p.size(), i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += (ll)p[i].first * p[j].second - (ll)p[i].second * p[j].first;

    int dx = abs(p[i].first - p[j].first), dy = abs(p[i].second - p[j].second);
    boundary_points += __gcd(dx, dy);
  }
  area = abs(area);

  ll interior_points = (area - boundary_points + 2) / 2;
  return interior_points + boundary_points;
}

int main() {
  vector<tinput> a = ReadInput();

  int x = 0, y = 0;
  vector<pii> p{{x, y}};
  for (auto [direction, steps] : a) {
    int dx = 0, dy = 0;
    if (direction == 'L') {
      dx = -1;
    }

    if (direction == 'R') {
      dx = 1;
    }

    if (direction == 'U') {
      dy = 1;
    }

    if (direction == 'D') {
      dy = -1;
    }

    x += dx * steps, y += dy * steps;
    p.push_back({x, y});
  }

  ll ans = Solve(p);

  cout << ans << endl;

  return 0;
}