#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y)
      : x(x), y(y) {}
  PT(const PT& p)
      : x(p.x), y(p.y) {}
  PT operator+(const PT& p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT& p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
};

double dot(PT p, PT q) {
  return p.x * q.x + p.y * q.y;
}
double dist2(PT p, PT q) {
  return dot(p - q, p - q);
}
double cross(PT p, PT q) {
  return p.x * q.y - p.y * q.x;
}

PT ReadPoint() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return PT(x, y);
}

string Solve() {
  PT p1 = ReadPoint();
  PT p2 = ReadPoint();
  PT p3 = ReadPoint();

  double c = cross(p2 - p1, p3 - p1);

  if (c > 0) {
    return "LEFT";
  }

  if (c < 0) {
    return "RIGHT";
  }

  return "TOUCH";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}