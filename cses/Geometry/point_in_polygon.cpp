#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double EPS = 1e-12;

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

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS)
    return a;
  r = dot(c - a, b - a) / r;
  if (r < 0)
    return a;
  if (r > 1)
    return b;
  return a + (b - a) * r;
}

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInsidePolygon(const vector<PT>& p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
         p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT>& p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}

string PointInPolygon(vector<PT>& polygon, PT& point) {
  if (PointOnPolygon(polygon, point)) {
    return "BOUNDARY";
  }

  return PointInsidePolygon(polygon, point) ? "INSIDE" : "OUTSIDE";
}

PT ReadPoint() {
  int x, y;
  scanf("%d%d", &x, &y);
  return PT(x, y);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<PT> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = ReadPoint();
  }

  while (q--) {
    PT a = ReadPoint();
    printf("%s\n", PointInPolygon(p, a).c_str());
  }

  return 0;
}