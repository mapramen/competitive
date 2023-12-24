#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tposition tuple<ll, ll, ll>
#define tvelocity tuple<ll, ll, ll>
#define tinput pair<tposition, tvelocity>

const double EPS = 1e-12;
const ll MIN_COORDINATE = 200000000000000, MAX_COORDINATE = 400000000000000;

struct pt {
  double x, y;
};

struct line {
  double a, b, c;
};

double det(double a, double b, double c, double d) {
  return a * d - b * c;
}

bool parallel(line m, line n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(line m, line n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS && abs(det(m.a, m.c, n.a, n.c)) < EPS && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

bool intersect(line m, line n, pt& res) {
  if (parallel(m, n)) {
    return false;
  }
  double zn = det(m.a, m.b, n.a, n.b);
  res.x = -det(m.c, m.b, n.c, n.b) / zn;
  res.y = -det(m.a, m.c, n.a, n.c) / zn;
  return true;
}

vector<tinput> ReadInput() {
  vector<tinput> input;
  while (true) {
    ll px, py, pz, vx, vy, vz;
    if (scanf("%lld, %lld, %lld @ %lld, %lld, %lld", &px, &py, &pz, &vx, &vy, &vz) == EOF) {
      break;
    }
    input.push_back({{px, py, pz}, {vx, vy, vz}});
  }
  return input;
}

line CalculateLine(tinput& input) {
  auto [position, velocity] = input;
  auto [px, py, pz] = position;
  auto [vx, vy, vz] = velocity;

  return {vy, -vx, vx * py - vy * px};
}

int main() {
  vector<tinput> a = ReadInput();

  int ans = 0;
  for (int n = a.size(), i = 0; i < n; ++i) {
    // printf("%d\n", i);
    line p = CalculateLine(a[i]);
    for (int j = i + 1; j < n; ++j) {
      line q = CalculateLine(a[j]);
      pt res;

      if (parallel(p, q) || equivalent(p, q) || !intersect(p, q, res)) {
        continue;
      }

      if (res.x < MIN_COORDINATE || res.x > MAX_COORDINATE || res.y < MIN_COORDINATE || res.y > MAX_COORDINATE) {
        continue;
      }

      double t1 = (res.x - get<0>(a[i].first)) / get<0>(a[i].second);
      double t2 = (res.x - get<0>(a[j].first)) / get<0>(a[j].second);

      if (t1 < 0 || t2 < 0) {
        continue;
      }

      printf("%d %d\n", i, j);
      ++ans;
    }
  }

  printf("%d\n", ans);

  return 0;
}