#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tinput tuple<char, int>

int ExtractNumber(string& s) {
  while (!s.empty() && !isdigit(s.back())) {
    s.pop_back();
  }

  int number = 0;
  while (!s.empty() && isdigit(s.back())) {
    number = 10 * number + (s.back() - '0');
    s.pop_back();
  }

  return number;
}

vector<tinput> ReadInput() {
  vector<tinput> a;
  while (true) {
    string s;
    if (!getline(cin, s) || s.empty()) {
      break;
    }

    reverse(s.begin(), s.end());

    char direction = s.back();
    s.pop_back();

    int steps = ExtractNumber(s);
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