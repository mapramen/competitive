#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pdd pair< double, double >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< pair< pll, pll > > intersectionPoints;

ll Distance(ll a, ll b, ll c, ll x, ll y){
  ll dis = a * x + b * y + c;
  // printf("%lld %lld %lld %lld %lld %lld %.15lf\n", a, b, c, x, y, dis, -1.0 * (a *x + c) / b);
  return dis;
}

bool CheckAndAddIntersectionPoint(ll a, ll b, ll c, ll x, ll y1, ll y2, bool flipXY){
  if(b < 0){
    b = -b, a = -a, c = -c;
  }

  if(y1 > y2){
    swap(y1, y2);
  }

  if(Distance(a, b, c, x, y1) > 0 || Distance(a, b, c, x, y2) < 0){
    return 0;
  }

  ll y = - (a * x + c);
  ll g = __gcd(abs(y), abs(b));
  y /= g, b /= g;
  if(b < 0){
    y = -y, b = -b;
  }

  if(flipXY){
    intersectionPoints.PB(MP(MP(y, b), MP(x, 1ll)));
  }
  else{
    intersectionPoints.PB(MP(MP(x, 1ll), MP(y, b)));
  }

  return 1;
}

double Dis(double x1, double y1, double x2, double y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Calculate(pll p){
  return (1.0 * p.first) / p.second;
}

double Solve(double x1, double y1, double x2, double y2){
  vector< pdd > v;

  v.PB(MP((double)x1, (double)y1));

  for(auto p : intersectionPoints){
    v.PB(MP(Calculate(p.first), Calculate(p.second)));
  }

  v.PB(MP((double)x2, (double)y2));

  double ans = 0;
  for(int i = 0; i < v.size() - 1; ++i){
    if(i != 1 && (v[i].first != v[i + 1].first) && (v[i].second != v[i + 1].second)){
      return 1E18;
    }
    ans += Dis(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
  }

  return ans;
}

int main(){
  ll a, b, c, x1, x2, y1, y2;

  cin >> a >> b >> c;
  cin >> x1 >> y1 >> x2 >> y2;

  if(a == 0 || b == 0){
    printf("%.15lf\n", 1.0 * abs(x1 - x2) + abs(y1 - y2));
    return 0;
  }

  double ans = abs(x1 - x2) + abs(y1 - y2);

  CheckAndAddIntersectionPoint(b, a, c, y1, x1, x2, 1);
  CheckAndAddIntersectionPoint(a, b, c, x2, y1, y2, 0);
  CheckAndAddIntersectionPoint(a, b, c, x1, y1, y2, 0);
  CheckAndAddIntersectionPoint(b, a, c, y2, x1, x2, 1);

  sort(intersectionPoints.begin(), intersectionPoints.end());
  intersectionPoints.erase(unique(intersectionPoints.begin(), intersectionPoints.end()), intersectionPoints.end());

  ans = min(ans, Solve(x1, y1, x2, y2));
  ans = min(ans, Solve(x2, y2, x1, y1));

  printf("%.15lf\n", ans);

  return 0;
}
