#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pid pair<int, double>

double Solve() {
  int n;
  scanf("%d", &n);

  vector<tuple<int, int, int>> v;
  while (n--) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    v.push_back({d, a, b});
  }
  sort(v.begin(), v.end());

  double t = 0, ans = 0;
  priority_queue<pid> Q;
  for (auto [d, a, b] : v) {
    t += b;
    Q.push({a, b});

    while (t > d) {
      auto [a, b] = Q.top();
      Q.pop();

      double dt = min(t - d, b);

      ans += dt / a;

      b -= dt;
      t -= dt;

      if (b > 0) {
        Q.push({a, b});
      }
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.2f\n", Solve());
  }
  return 0;
}