#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define M 100

vector<pdd> Query(int n, double a, double b) {
  printf("? %lf %lf 0\n", a, b);
  fflush(stdout);

  vector<pdd> ans(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &ans[i].first, &ans[i].second);
  }
  return ans;
}

set<double> GetXCoordinates(int n) {
  set<double> x_coordinates;
  for (auto [x, y] : Query(n, 0, 1)) {
    x_coordinates.insert(x);
  }
  return x_coordinates;
}

set<double> GetYCoordinates(int n) {
  set<double> y_coordinates;
  for (auto [x, y] : Query(n, 1, 0)) {
    y_coordinates.insert(y);
  }
  return y_coordinates;
}

double Dist2(pdd& a, pdd& b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

pdd GetBestMatch(set<double>& x_coordinates, set<double>& y_coordinates, double m, pdd expected_projection) {
  double best_dist = 1e18;
  pdd best_match = {0, 0};
  for (double x : x_coordinates) {
    for (double y : y_coordinates) {
      pdd actual_projection = {(x + m * y) / (1 + m * m), (m * x + m * m * y) / (1 + m * m)};
      double dist = Dist2(actual_projection, expected_projection);
      if (dist < best_dist) {
        best_dist = dist;
        best_match = {x, y};
      }
    }
  }
  return best_match;
}

vector<pdd> Solve() {
  int n;
  scanf("%d", &n);

  double m = 1.0 / (4 * M);

  set<double> x_coordinates = GetXCoordinates(n);
  set<double> y_coordinates = GetYCoordinates(n);
  vector<pdd> expected_projections = Query(n, m, -1);

  vector<pdd> ans;
  for (pdd& expected_projection : expected_projections) {
    auto [x, y] = GetBestMatch(x_coordinates, y_coordinates, m, expected_projection);
    x_coordinates.erase(x), y_coordinates.erase(y);
    ans.push_back({x, y});
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<pdd> ans = Solve();
    printf("! ");
    for (auto [x, y] : ans) {
      printf("%lf %lf ", x, y);
    }
    printf("\n");
    fflush(stdout);
  }
  return 0;
}