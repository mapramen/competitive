#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAX_X 1000000

double eps = 1E-9;
ll s;
vector< pll > lft, rght;

bool Check(double t){
  vector< pii > lSegments, rSegments;

  for(auto p : lft){
    ll x, v;
    int l, r;

    tie(x, v) = p;
    if((v + s) * t < x)
      continue;

    if(v * t >= x)
      l = 0, r = MAX_X;
    else{
      l = x;
      double d = floor((t * (s - v) * (s + v) + x * v) / s);
      d = min(d, 1.0 * MAX_X);
      r = (int)d;
    }

    if(l <= r)
      lSegments.PB(MP(l, r));
  }

  for(auto p : rght){
    ll x, v;
    int l, r;

    tie(x, v) = p;
    if((v + s) * t < MAX_X - x)
      continue;

    if(v * t >= MAX_X - x)
      l = 0, r = MAX_X;
    else{
      r = x;
      double d = ceil((x * v + (s - v) * MAX_X - t * (s - v) * (s + v)) / s);
      d = max(0.0, d);
      l = (int)d;
    }

    if(l <= r)
      rSegments.PB(MP(l, r));
  }

  sort(lSegments.begin(), lSegments.end());
  sort(rSegments.begin(), rSegments.end());

  bool valid = 0;
  priority_queue< int, vector<int>, greater<int> > Q;

  for(int i = 0, j = 0; i < lSegments.size() && j < rSegments.size() && valid == 0; i++){
    for( ; j < rSegments.size() && rSegments[j].first <= lSegments[i].second; j++)
      Q.push(rSegments[j].second);

    while(!Q.empty() && Q.top() < lSegments[i].first)
      Q.pop();

    valid = !Q.empty();
  }

  return valid;
}

double BinarySearch(){
  double x = 0, y = MAX_X, z = y;
  while(y - x >= eps){
    double mid = x + (y - x) / 2;
    if(Check(mid))
      z = mid, y = mid - eps;
    else
      x = mid + eps;
  }
  return z;
}

int main(){
  int n;

  scanf("%d%lld", &n, &s);
  while(n--){
    int t;
    ll x, v;
    scanf("%lld%lld%d", &x, &v, &t);
    if(t == 1)
      lft.PB(MP(x, v));
    else
      rght.PB(MP(x, v));
  }

  printf("%.15lf\n", BinarySearch());

  return 0;
}
