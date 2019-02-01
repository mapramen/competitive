#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

int n;
vector< PT > p;

int main(){
  cin >> n;
  double ans = 2E9;

  while(n--){
    double x, y;
    cin >> x >> y;
    p.PB(PT(x, y));
  }

  n = p.size();

  for(int i = 0; i < n; i++){
    int j = (i + 1) % n, k = (i + 2) % n;
    double d = 2 * sqrt(dist2(p[i], p[k]));
    double area = abs(cross(p[i] - p[j], p[k] - p[j]));
    ans = min(ans, area / d);
  }

  printf("%.9lf\n", ans);

  return 0;
}
